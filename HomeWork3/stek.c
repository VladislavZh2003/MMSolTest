void outerFunction()
{
    int outerVariable = 10;
    innerFunction();
}
void innerFunction()
{
    int innerVariable = 20;
}
int main()
{
    outerFunction();
    return 0;
}