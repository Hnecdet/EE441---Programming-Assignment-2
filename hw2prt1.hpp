#include <iostream>
#include <fstream>
#include <ostream>
using namespace std;
///////////////////////////7//Maze/////////////////////
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

class Maze
{
    private:
		// next is the address of the following node
        char **state;
        int col,row;
    public:
		// constructor
        Maze ();
        bool can_move_left();
        bool can_move_forward();
        bool can_move_right();
        bool can_move_back();
        void move_left();
        void move_forward();
        void move_right();
        void move_back();
        void print_state();
        bool is_solved();
        ~Maze ();
};

// constructor. initialize data and pointer members
Maze::Maze()
{
    /* reading the maze from file */
     ifstream input_file; /* input file stream */
     input_file.open ("input_maze.txt");
     int nrow, ncol; /* number of rows and columns */
     input_file >> nrow >> ncol; /* read the size from file */
     if(nrow<20 && ncol<20 && 0<nrow && 0<ncol){
            row = nrow;
            col = ncol;

            state = new char* [nrow];
            for(int i = 0; i < nrow; ++i) {
                state[i] = new char[ncol];
            }

            for(int i=0; i<nrow; ++i){
                for(int j=0; j<ncol; ++j){
                    input_file >> state[i][j];
                }
            }
        }
    else
        cerr << "ERROR!";
    input_file.close();
}
bool Maze ::can_move_left(){
    for(int i=0; i<row; ++i){
        for(int j=0; j<col; ++j){
            if(state[i][j]== 'E' || state[i][j]== 'N' || state[i][j]== 'S' || state[i][j]== 'W'){
                if(state[i][j]== 'E'){
                    if(state[i-1][j]== '#') return false;
                    else return true;}
                else if(state[i][j]== 'N'){
                    if(state[i][j-1]== '#') return false;
                    else return true;}
                else if(state[i][j]== 'S'){
                    if(state[i][j+1]== '#') return false;
                    else return true;}
                else if(state[i][j]== 'W'){
                    if(state[i+1][j]== '#') return false;
                    else return true;}
}}}}
bool Maze ::can_move_back(){
    for(int i=0; i<row; ++i){
        for(int j=0; j<col; ++j){
            if(state[i][j]== 'E' || state[i][j]== 'N' || state[i][j]== 'S' || state[i][j]== 'W'){
                if(state[i][j]== 'E'){
                    if(state[i][j-1]== '#') return false;
                    else return true;}
                else if(state[i][j]== 'N'){
                    if(state[i+1][j]== '#') return false;
                    else return true;}
                else if(state[i][j]== 'S'){
                    if(state[i-1][j]== '#') return false;
                    else return true;}
                else if(state[i][j]== 'W'){
                    if(state[i][j+1]== '#') return false;
                    else return true;}
}}}}
bool Maze ::can_move_right(){
    for(int i=0; i<row; ++i){
        for(int j=0; j<col; ++j){
            if(state[i][j]== 'E' || state[i][j]== 'N' || state[i][j]== 'S' || state[i][j]== 'W'){
                if(state[i][j]== 'E'){
                    if(state[i+1][j]== '#') return false;
                    else return true;}
                else if(state[i][j]== 'N'){
                    if(state[i][j+1]== '#') return false;
                    else return true;}
                else if(state[i][j]== 'S'){
                    if(state[i][j-1]== '#') return false;
                    else return true;}
                else if(state[i][j]== 'W'){
                    if(state[i-1][j]== '#') return false;
                    else return true;}
}}}}
bool Maze ::can_move_forward(){
    for(int i=0; i<row; ++i){
        for(int j=0; j<col; ++j){
            if(state[i][j]== 'E' || state[i][j]== 'N' || state[i][j]== 'S' || state[i][j]== 'W'){
                if(state[i][j]== 'E'){
                    if(state[i][j+1]== '#') return false;
                    else return true;}
                else if(state[i][j]== 'N'){
                    if(state[i-1][j]== '#') return false;
                    else return true;}
                else if(state[i][j]== 'S'){
                    if(state[i+1][j]== '#') return false;
                    else return true;}
                else if(state[i][j]== 'W'){
                    if(state[i][j-1]== '#') return false;
                    else return true;}
}}}}
void Maze ::move_left(){
    char C;
    int cur_row,cur_col;
    if(can_move_left()){
        for(int i=0; i < row ; i++){
            for(int j=0; j < col ; j++){
                if(state[i][j] == 'E' || state[i][j] == 'N' || state[i][j] == 'S' || state[i][j] == 'W' ){
                    C = state[i][j];
                    cur_row = i;
                    cur_col = j;
                    break;}}}

        if(C== 'E'){
            state[cur_row][cur_col]= 'N';
            if(state[cur_row-1][cur_col]=='T'){
                    state[cur_row-1][cur_col] = '.';}
            swap(state[cur_row-1][cur_col],state[cur_row][cur_col]);}
        if(C== 'N'){
            state[cur_row][cur_col]= 'W';
            if(state[cur_row][cur_col-1]=='T'){
                    state[cur_row][cur_col-1] = '.';}
            swap(state[cur_row][cur_col-1],state[cur_row][cur_col]);}
        if(C== 'S'){
            state[cur_row][cur_col]= 'E';
            if(state[cur_row][cur_col+1]=='T'){
                    state[cur_row][cur_col+1] = '.';}
            swap(state[cur_row][cur_col+1],state[cur_row][cur_col]);}
        if(C == 'W'){
            state[cur_row][cur_col]= 'S';
            if(state[cur_row+1][cur_col]=='T'){
                    state[cur_row+1][cur_col] = '.';}
            swap(state[cur_row+1][cur_col],state[cur_row][cur_col]);}}
    else
        cerr    << "You can not move left";
    }
void Maze ::move_back(){
    char C;
    int cur_row,cur_col;
    if(can_move_back()){
        for(int i=0; i < row ; i++){
            for(int j=0; j < col ; j++){
                if(state[i][j] == 'E' || state[i][j] == 'N' || state[i][j] == 'S' || state[i][j] == 'W' ){
                    C = state[i][j];
                    cur_row = i;
                    cur_col = j;
                    break;}}}}
        if(C== 'E'){
            state[cur_row][cur_col]= 'W';
            if(state[cur_row][cur_col-1]=='T'){

                state[cur_row][cur_col-1] = '.';}
            swap(state[cur_row][cur_col-1],state[cur_row][cur_col]);}

        else if(C== 'N'){
            if(state[cur_row+1][cur_col]=='T'){
                state[cur_row+1][cur_col] = '.';}
            state[cur_row][cur_col]= 'S';
            swap(state[cur_row+1][cur_col],state[cur_row][cur_col]);}
        else if(C== 'S'){
            if(state[cur_row-1][cur_col]=='T'){
                state[cur_row-1][cur_col] = '.';}
            state[cur_row][cur_col]= 'N';
            swap(state[cur_row-1][cur_col],state[cur_row][cur_col]);}

        else if(C== 'W'){
            if(state[cur_row][cur_col+1]=='T'){

                state[cur_row][cur_col+1] = '.';}
            state[cur_row][cur_col]= 'E';
            swap(state[cur_row][cur_col+1],state[cur_row][cur_col]);}
    else
        cerr    << "You can not move back";
    }
void Maze ::move_forward(){
    char C;
    int cur_row,cur_col;
    if(can_move_forward()){
        for(int i=0; i < row ; i++){
            for(int j=0; j < col ; j++){
                if(state[i][j] == 'E' || state[i][j] == 'N' || state[i][j] == 'S' || state[i][j] == 'W' ){
                    C = state[i][j];
                    cur_row = i;
                    cur_col = j;
                    break;}}}}

        if(C== 'E'){
            if(state[cur_row][cur_col+1]=='T'){
                state[cur_row][cur_col+1] = '.';}
            swap(state[cur_row][cur_col+1],state[cur_row][cur_col]);}
        else if(C== 'N'){
            if(state[cur_row-1][cur_col]=='T'){
                state[cur_row-1][cur_col] = '.';}
            swap(state[cur_row-1][cur_col],state[cur_row][cur_col]);}
        else if(C== 'S'){
            if(state[cur_row+1][cur_col]=='T'){
                state[cur_row+1][cur_col] = '.';}
            swap(state[cur_row+1][cur_col],state[cur_row][cur_col]);}
        else if(C== 'W'){
            if(state[cur_row][cur_col-1]=='T'){
                state[cur_row][cur_col-1] = '.';}
            swap(state[cur_row][cur_col-1],state[cur_row][cur_col]);}
    else
        cerr    << "You can not move forward";
}
void Maze ::move_right(){
    char C;
    int cur_row,cur_col;
    if(can_move_right()){
        for(int i=0; i < row ; i++){
            for(int j=0; j < col ; j++){
                if(state[i][j] == 'E' || state[i][j] == 'N' || state[i][j] == 'S' || state[i][j] == 'W' ){
                    C = state[i][j];
                    cur_row = i;
                    cur_col = j;
                    break;}}}}

        if(C== 'E'){
                state[cur_row][cur_col]='S';
                if(state[cur_row+1][cur_col]=='T'){
                    state[cur_row+1][cur_col] = '.';}
                swap(state[cur_row+1][cur_col],state[cur_row][cur_col]);}

        else if(C== 'N'){
                state[cur_row][cur_col]='E';
                if(state[cur_row][cur_col+1]=='T'){
                    state[cur_row][cur_col+1] = '.';}
                swap(state[cur_row][cur_col+1],state[cur_row][cur_col]);}
        else if(C== 'S'){
                state[cur_row][cur_col]='W';

                swap(state[cur_row][cur_col-1],state[cur_row][cur_col]);}
        else if(C== 'W'){
                if(state[cur_row-1][cur_col]=='T'){
                    state[cur_row-1][cur_col] = '.';}
                state[cur_row][cur_col]='N';
                swap(state[cur_row-1][cur_col],state[cur_row][cur_col]);}
    else
        cerr    << "You can not move right";
    }
void Maze ::print_state(){
    for(int i=0; i<row; ++i){
        for(int j=0; j<col; ++j){
            cout << state[i][j];}
        cout<< endl;}}
bool Maze::is_solved(){
    bool solve = true;

    for(int i=0; row>i ; i++){
        for(int j=0; col>j ; j++){
            if(state[i][j] == 'T'){
                solve = false;
                break;
            }
        }
    }
    return solve;
}
Maze::~Maze(){
        //Free each sub-array (row)
for(int i = 0; i< row; ++i) {
delete[] state[i];
        }
delete[] state;  //Free the array of pointers
}

///////////////////////////7//StackQueue/////////////////////
const int MaxStackSize=1036;
template <class T>
class Stack
{
private:
T stacklist[MaxStackSize];
int top;
public:
Stack(void); // constructor to initialize top
//modification operations
void Push(const T& item);
T Pop(void);
//just copy top item without modifying stack contents
T Peek(void) const;
//check stack state returns top element value without removal
int StackEmpty(void) const;
//returns true if the stack is empty
int StackFull(void) const;
//returns true if the stack is full
};
template <class T>
Stack<T>::Stack(void):top(-1)
{}
template <class T>
//Push
void Stack<T>::Push(const T& item){
//can not push if stack has exceeded its limits
    if (top==MaxStackSize-1)
{
cerr<<"Stack overflow"<<endl;
exit(1);
}
// increment top and copy item into list
top++;
stacklist[top] = item;
}
template <class T>
//pop
T Stack<T>::Pop(void){
    T temp;
    // is stack empty nothing to pop
    if (top==-1)
    {
    cerr<<"Stack empty"<<endl;
    exit(1);
    }
    //record the top element
    temp=stacklist[top] ;
    //decrement top and return the earlier top element
    top--;
    return temp;
}
template <class T>
//Peek is the same as Pop, except top is not moved
T Stack<T>::Peek(void) const{ //just copy top item without modifying stack contents
    T temp;

    temp=stacklist[top] ;
    return temp;
}
template <class T>
//StackEmpty: returns true if the stack is empty
int Stack<T>::StackEmpty(void) const{
    return top==-1;
}
template <class T>
//StackFull: returns true if the stack is full
int Stack<T>::StackFull(void) const{
    return top==(MaxStackSize-1);
}
template <class T>
class StackQueue{
    private:

        Stack<T> SLIFO,SFIFO;
    public:
        int length=0;

        StackQueue (void);
        void push_front (const T &item);
        void push_rear (const T &item);
        T pop_front (void);
        T pop_rear (void);
        T peek_front (void) const;
        void print_elements (void);


};
template <class T>
StackQueue<T>::StackQueue(void)
{}
template <class T>
void StackQueue<T>::push_front (const T &item){
    if(SLIFO.StackFull()){
        cerr<<"FULL!" <<endl;
        exit(1);}
    else SLIFO.Push(item);
    length++;
}
template <class T>
void StackQueue<T>::push_rear (const T &item){
    if(SLIFO.StackFull()){
        cerr<<"FULL!" <<endl;
        exit(1);}
    else {
        while(!SLIFO.StackEmpty())
            SFIFO.Push(SLIFO.Pop());
        SFIFO.Push(item);
        while(!SFIFO.StackEmpty())
            SLIFO.Push(SFIFO.Pop());
    }
    length++;

}
template <class T>
T StackQueue<T>::pop_front (){
    T temp;
    if(SLIFO.StackEmpty()){
        cerr<<"EMPTY!" <<endl;
        exit(1);}
    temp = SLIFO.Pop();
    return temp;
    length--;
}
template <class T>
T StackQueue<T>::pop_rear (){
    T temp;
    if(SLIFO.StackEmpty()){
        cerr<<"FULL!" <<endl;
        exit(1);}
    while(!SLIFO.StackEmpty())
        SFIFO.Push(SLIFO.Pop());
    temp = SFIFO.Pop();
    while(!SFIFO.StackEmpty())
        SLIFO.Push(SFIFO.Pop());
    length--;

    return temp;
    }
template <class T>
T StackQueue<T>::peek_front()const{
    T temp;
    temp = SLIFO.Peek();
    return temp;
}
template <class T>
void StackQueue<T>::print_elements (void){
    T temp;
    while(!SLIFO.StackEmpty())
        SFIFO.Push(SLIFO.Pop());
    while(!SFIFO.StackEmpty()){
        temp = SFIFO.Pop();
        SLIFO.Push(temp);
        cout <<temp;}
}

