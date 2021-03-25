// функция удаления элемента из очереди
template<typename T>
T Queue<T>::dequeue()
{
    // проверяем, есть ли в очереди элементы
    assert( elemCT > 0 );

    T returnValue = queuePtr[begin++];
    elemCT--;

    // проверка кругового заполнения очереди
    if (begin > size)
        begin -= size + 1; // возвращаем behin на начало очереди

    return returnValue;
}
