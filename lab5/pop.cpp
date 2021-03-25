public T Pop()
{
    if (_items.Count == 0)
    {
        throw new InvalidOperationException("The stack is empty");
    }

    T result = _items.Tail.Value;

    _items.RemoveLast();

    return result;
}
