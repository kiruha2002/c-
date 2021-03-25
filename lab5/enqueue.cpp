// ������� ���������� �������� � �������
template<typename T>
void Queue<T>::enqueue(const T &newElem)
{
    // ���������, ���� �� ��������� ����� � �������
    assert( elemCT < size );

    // �������� �������� �� ��, ��� ������� �������� ����������� � 0 �������
    queuePtr[end++] = newElem;

    elemCT++;

    // �������� ��������� ���������� �������
    if (end > size)
        end -= size + 1; // ���������� end �� ������ �������
}
