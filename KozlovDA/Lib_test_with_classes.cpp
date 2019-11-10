#include "Lib_classes.h"

void ba_dom_tss(int dots) {
	for (int i = 0; i < dots; i++) {
		std::cout << ". ";
		Sleep(1000);
	}
	std::cout << '\n';
}

void processing_of_answer(std::string right_answer, std::string answer) {
	setlocale(LC_ALL, "Russian");
	while (answer != right_answer) {
		std::cout << "Íåâåðíî. Ïîïðîáóéòå åùå ðàç." << '\n';
		std::cin >> answer;
	}
	std::cout << "Âåðíî\n" << '\n';
	Sleep(500);
}
