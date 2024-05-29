
#include <iostream>

class Stack{
private:
    int index;
    int start;
    int end;
    int *array;
    int arraySize;

public:
    Stack(){}


    int getSize() const {
        return end < start ? arraySize - start + end : end - start;
    }

    int getStart() const {
        return start;
    }

    void setStart(int start) {
        Stack::start = start;
        index = start;
    }

    void setAnEnd(int anEnd) {
        end = anEnd;
    }

    int getAnEnd() const {
        return end;
    }

    void setArray(int *array, int arraySize) {
        Stack::array = array;
        Stack::arraySize = arraySize;
    }


    void moveElementsToTheRight(){
        int temp;
        for(int idx = start; idx != end; moveIndex(idx)){
            temp = array[start];
            array[start] = array[idx];
            array[idx] = temp;
        }
    }


    void moveEndToTheRight()
    {
        moveIndex(end);
    }

    void moveStartToTheRight()
    {
        moveIndex(start);
        moveIndex(index);
    }


    bool isFull() {
        return index == end;
    }

    void moveIndex(int &_index)
    {
        _index = _index + 1 == arraySize ? 0 : _index + 1;
    }

    bool push(int value)
    {
        if (isFull())
            return false;
        array[index] = value;
        moveIndex(index);
        return true;
    }

    void pop(){

    }



    void printValues()
    {
        for (int i = start; i < end; i++)
        {
            std::cout << array[i] << (i == end - 1 ? "" : ", ");
        }
        std::cout << "\n";
    }



};


class StackHandler{
private:
    Stack *stacks;
    int *array;
    int numOfStacks;
    int defaultStackSize;

public:
    StackHandler(int _numOfStacks, int arraySize) : numOfStacks(_numOfStacks){
        if (numOfStacks > arraySize)
            throw std::invalid_argument("Not enough space for the Stacks");

        array = new int[arraySize]();

        int rest = arraySize % _numOfStacks;
        int pSize = arraySize / _numOfStacks;
        int counter = 0;
        stacks = new Stack[_numOfStacks];
        for(int i = 0; i < _numOfStacks; i++){
            int finalSize = rest-- > 0 ? pSize + 1 : pSize;
            stacks[i].setStart(!counter ? 0 : counter);
            stacks[i].setAnEnd(counter += finalSize);
            stacks[i].setArray(array, arraySize);
        }

        for(int i = 0; i < _numOfStacks; i++)
        {
            std::cout << stacks[i].getSize() << " | " << stacks[i].getStart() << " | " << stacks[i].getAnEnd() <<  std::endl;
        }

    }

    void printStacks(){
        for (int i = 0; i < numOfStacks; ++i) {
            stacks[i].printValues();
        }
    }


    void addElementToStack(int numOfStack, int value) {
        if (numOfStack > numOfStacks - 1 || numOfStack < 0)
            throw std::invalid_argument("Index not found!");
        if (!stacks[numOfStack].push(value)){
            std::cout << " is full!! we have to resize" << std::endl;
            int it = numOfStack == numOfStacks - 1 ? 0 : numOfStack + 1;
            bool hasFoundCandidate = false;
            // finds candidate
            while(it != numOfStack && !hasFoundCandidate)
            {
                if (!stacks[it].isFull())
                {
                    hasFoundCandidate = true;
                } else
                {
                    it = (it == numOfStacks - 1 ? 0 : it + 1);
                }

            }
            stacks[it].moveElementsToTheRight();
            stacks[it].moveStartToTheRight();
            it = it == 0 ? numOfStacks - 1 : it - 1;
            // resize everything
            if (hasFoundCandidate) {
                while(it != numOfStack)
                {
                    stacks[it].moveElementsToTheRight();
                    stacks[it].moveStartToTheRight();
                    stacks[it].moveEndToTheRight();
                    it = (it == 0 ? numOfStacks - 1 : it - 1);
                }
            }
            stacks[numOfStack].moveEndToTheRight();
            stacks[numOfStack].push(value);



        }
    }

};



int main()
{
    StackHandler stackHandler(3, 9);
    stackHandler.addElementToStack(0, 3);
    stackHandler.addElementToStack(0, 14);
    stackHandler.addElementToStack(0, 19);
    stackHandler.addElementToStack(0, 20);
    stackHandler.addElementToStack(1, 16);
    stackHandler.printStacks();
    return 0;
}