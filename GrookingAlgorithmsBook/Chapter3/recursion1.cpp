// Pseudo code

// Example 1
/*
stack = create_stack();
while (stack.size() > 0)
{
    item = stack.pop();
    for (const auto& i : item)
    {
        if (i.is_box())
            stack.push(i);
        else if (item.is_klucz())
        {
            std::cout << "I found key!\n";
            return;
        }     
    }
}
*/

// Example 2
/*
void find_key(auto pudelko)
{
    for (const auto& item : pudelko)
    {
        if (item.is_pudelko())
            find_key(item); // Recursion
        else if (item.is_key())
        {
            std::cout << "I find_key!\n";
            return;
        }
    }
}
*/