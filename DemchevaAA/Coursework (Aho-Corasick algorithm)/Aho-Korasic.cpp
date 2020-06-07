#include <iostream>
#include <vector>

using namespace std;

const int k = 26; //k - размер алфавита

struct vertex 
{
  int next_vertex[k]; // номер вершины, в которую мы придем по символу с номером в алфавите
  int suff_link; // суффиксная ссылка
  int g_suff_link; //'хорошая' суффиксная ссылка
  int word_num; //номер слова, обозначаемого этой вершиной
  bool flag; //Флаг, обозначающий, что вершина является окончанием слова - терминальным состоянием
  int auto_move[k]; //Запись переходов автомата - для рассчета суфф ссылки
  int parent; //Номер вершины-родителя
  char symb; //Символ на ребре между parent и этой вершиной
};

vector <vertex> bohr; //Вектор для хранения бора
vector <string> pattern; //Вектор искомых слов

vertex create_vertex(int p, char c) 
{
  vertex v;
  memset(v.next_vertex, 255, sizeof(v.next_vertex));//В поле "следующая вершина" записываем "-1" - признак отсутствия ребра
  memset(v.auto_move, 255, sizeof(v.auto_move)); //Аналогично - для записи состояний
  v.flag = false;
  v.suff_link = -1; //изначально суф. ссылки нет
  v.g_suff_link = -1; //как и "хорошей" суф. ссылки
  v.parent = p;
  v.symb = c;
  return v;
}

void  create_root()
{
  bohr.push_back(create_vertex(0, '$'));
  return;
}

void add_word_to_bohr(const string& word1) 
{
  int vertex_num1 = 0; //Начинаем с корня   
  for (size_t i = 0; i < word1.length(); i++) 
  {
    char letter1 = word1[i] - 'a'; //Получаем номер текущей буквы в алфавите
  	if (bohr[vertex_num1].next_vertex[letter1] == -1)  //-1 - признак отсутствия ребра
  	{
  		bohr.push_back(create_vertex(vertex_num1, letter1)); //Добавляем новую вершину в вектор bohr
  		bohr[vertex_num1].next_vertex[letter1] = bohr.size() - 1; //В качестве ссылки на следующую вершину принимаем последнюю ячейку вектора bohr
  	}
  	vertex_num1 = bohr[vertex_num1].next_vertex[letter1]; //Переходим к следующей вершине
  }
  bohr[vertex_num1].flag = true; //Дойдя до конца слова, ставим флаг терминального состояния
  pattern.push_back(word1); //Добавляем ячейку в конце вектора для хранения слов
  bohr[vertex_num1].word_num = pattern.size() - 1; //Переходим к следующему слову
  return;
}

bool is_string_in_bohr(const string& word2) //Проверяем, есть ли строка в боре
{ 
  int vertex_num2 = 0; //Начинаем с корня 
  for (size_t i = 0; i < word2.length(); i++) //Для каждой буквы слова
  {
  	char letter2 = word2[i] - 'a';//Получаем номер текущей буквы в алфавите
  	if (bohr[vertex_num2].next_vertex[letter2] == -1)//Если перехода по нужной букве нет
  	{
  		return false;
  	}
  	vertex_num2 = bohr[vertex_num2].next_vertex[letter2];//Переходим к следующей вершине
  }
  return true;
}

int get_auto_move(int v, char letter);

int get_suff_link(int v) //Функция определения суффиксной ссылки
{
  if (bohr[v].suff_link == -1) //если ссылка еще не была найдена
  	if (v == 0 || bohr[v].parent == 0) //если текущий узел или его предок - корень
  	  bohr[v].suff_link = 0; //Принимаем в качестве ссылки 0
  	else
  	  bohr[v].suff_link = get_auto_move(get_suff_link(bohr[v].parent), bohr[v].symb);//Иначе - возвращаемся к родителю и запускаем поиск ссылки от него
  return bohr[v].suff_link;
}


int get_auto_move(int v, char letter)//Функция поиска суфф ссылки через переход к родителю
{
  if (bohr[v].auto_move[letter] == -1) //Если состояние уже было найдено
    if (bohr[v].next_vertex[letter] != -1)//Если определен переход к следующей вершине
      bohr[v].auto_move[letter] = bohr[v].next_vertex[letter];//Принимаем его в качестве суфф. ссылки
    else
      if (v == 0)//Если рассматриваемая вершина - корень
      	bohr[v].auto_move[letter] = 0; //Принимаем в качестве ссылки 0
      else
      	bohr[v].auto_move[letter] = get_auto_move(get_suff_link(v), letter);//Иначе - продолжаем поиск
  return bohr[v].auto_move[letter];
}

int get_g_suff_link(int v) 
{
  if (bohr[v].g_suff_link != -1)//если "хорошая" ссылка еще не найдена
  	return bohr[v].g_suff_link;
  int u = get_suff_link(v);
  if (u == 0) //если v - корень, или его суф. ссылка указывает на корень 
  	bohr[v].g_suff_link = 0;//Тогда "хорошая" ссылка = 0
  else
  {
  	if (bohr[u].flag)
      bohr[v].g_suff_link = u;
  	else
  	  bohr[v].g_suff_link = get_g_suff_link(u); 
  }
  return bohr[v].g_suff_link;
}

void check(int v, int i)// i - последняя рассмотренная буква в искомом слове
{
  for (int u = v; u != 0; u = get_g_suff_link(u))
  {
  	if (bohr[u].flag) //Если автомат пришел в терминальное состояние (достиг конца слова)
  	  cout << i - pattern[bohr[u].word_num].length() + 1 << " " << pattern[bohr[u].word_num] << endl;
  }
}

void find_all_pos(const string& s) 
{
  int u = 0;
  for (size_t i = 0; i < s.length(); i++)
  {
  	u = get_auto_move(u, s[i] - 'a');
  	check(u, i + 1);
  }
}

int main()
{
  create_root();
  add_word_to_bohr("abc");
  add_word_to_bohr("dcbc");
  add_word_to_bohr("ddbb");
  add_word_to_bohr("bcdd");
  add_word_to_bohr("bbbc");
  find_all_pos("dcbcddbbbcccbbbcccbbabc");
}
