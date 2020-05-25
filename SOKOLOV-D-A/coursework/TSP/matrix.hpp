#pragma once

#include <vector>
#include <stdio.h>

template<typename ItemType>
class Matrix {
 public:
    explicit Matrix(size_t size = 0, ItemType values = 0);

    // доступ к элементам по индексам
    const ItemType &item(size_t row, size_t column) const;
    ItemType &item(size_t row, size_t column);
    const ItemType &operator()(size_t row, size_t column) const;
    ItemType &operator()(size_t row, size_t column);

    // получение "реальных" идексов
    // e.g. если была удалена строка 1 rowIndex(1) == 2
    // ?необходимо для алгоритма Литтла
    size_t rowIndex(size_t row) const;
    size_t columnIndex(size_t column) const;

    // размерность матрицы
    size_t size() const;
    // вывод на экран
    void print() const;
    void printEndl() const;

    // удаление строки и столбца по индексам
    void removeRowColumn(size_t row, size_t column);

    Matrix(const Matrix &) = default;
    Matrix &operator=(const Matrix &) = default;

 private:
    // инициализация "реальных" номеров строк и столбцов
    void initRowsColumns();

    std::vector<std::vector<ItemType>> _items;
    // "реальные" номера строк
    std::vector<size_t> _rows;
    // "реальные" номера столбцов
    std::vector<size_t> _columns;
};

template<typename ItemType>
inline Matrix<ItemType>::Matrix(size_t size, ItemType values)
    :_items(size, std::vector<ItemType>(size, values)), _rows(size), _columns(size) {
    initRowsColumns();
}

template<typename ItemType>
inline const ItemType & Matrix<ItemType>::item(size_t row, size_t column) const {
    return _items[row][column];
}

template<typename ItemType>
inline ItemType & Matrix<ItemType>::item(size_t row, size_t column) {
    // по имя искоренения дублирования кода
    return const_cast<ItemType&>(static_cast<const Matrix<ItemType>&>(*this).item(row, column));
}

template<typename ItemType>
inline const ItemType & Matrix<ItemType>::operator()(size_t row, size_t column) const {
    return item(row, column);
}

template<typename ItemType>
inline ItemType & Matrix<ItemType>::operator()(size_t row, size_t column) {
    return item(row, column);
}

template<typename ItemType>
inline size_t Matrix<ItemType>::rowIndex(size_t row) const {
    return _rows[row];
}

template<typename ItemType>
inline size_t Matrix<ItemType>::columnIndex(size_t column) const {
    return _columns[column];
}

template<typename ItemType>
inline void Matrix<ItemType>::removeRowColumn(size_t row, size_t column) {
    // удаление индексов
    _rows.erase(_rows.begin() + row);
    _columns.erase(_columns.begin() + column);
    // удаление строки
    _items.erase(_items.begin() + row);
    // удаление столбца
    for (size_t i = 0; i < _items.size(); i++)
        _items[i].erase(_items[i].begin() + column);
}

template<typename ItemType>
inline size_t Matrix<ItemType>::size() const {
    return _items.size();
}

template<typename ItemType>
inline void Matrix<ItemType>::print() const {
    printf("         ");
    for (auto iter = _columns.cbegin(); iter != _columns.cend(); ++iter)
        printf("%8u ", *iter);
    puts("");
    for (size_t i = 0; i < _items.size(); i++) {
        printf("%8u ", _rows[i]);
        for (size_t j = 0; j < _items.size(); j++) {
            printf("%8.2f ", _items[i][j]);
        }
        puts("");
    }
}

template<typename ItemType>
inline void Matrix<ItemType>::printEndl() const {
    print();
    puts("");
}

template<typename ItemType>
inline void Matrix<ItemType>::initRowsColumns() {
    for (size_t i = 0; i < _rows.size(); i++)
        _rows[i] = _columns[i] = i;
}
