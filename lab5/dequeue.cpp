// ������� �������� �������� �� �������
template<typename T>
T Queue<T>::dequeue()
{
    // ���������, ���� �� � ������� ��������
    assert( elemCT > 0 );

    T returnValue = queuePtr[begin++];
    elemCT--;

    // �������� ��������� ���������� �������
    if (begin > size)
        begin -= size + 1; // ���������� behin �� ������ �������

    return returnValue;
}
