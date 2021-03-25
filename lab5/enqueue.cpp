// функция добавления элемента в очередь
template<typename T>
void Queue<T>::enqueue(const T &newElem)
{
    // проверяем, ести ли свободное место в очереди
    assert( elemCT < size );

    // обратите внимание на то, что очередь начинает заполняться с 0 индекса
    queuePtr[end++] = newElem;

    elemCT++;

    // проверка кругового заполнения очереди
    if (end > size)
        end -= size + 1; // возвращаем end на начало очереди
}
