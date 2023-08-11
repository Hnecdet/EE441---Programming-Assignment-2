#include <iostream>
#include "hw2prt1.hpp"
using namespace std;
int main(){
cout<< "First Pass: "   << endl;
/////////////////PART 1.3 //////////////////////////////
//1. pass
Maze solve_maze;
Maze solve_maze2;
StackQueue<char> stckque;

while(solve_maze.is_solved()!= true){
    cout << "SQ: ";
    stckque.print_elements();
    cout<<endl;
    solve_maze.print_state();
    cout<<endl;

    if(solve_maze.can_move_left()){
            StackQueue<char> control;
            solve_maze.move_left();
            if(stckque.peek_front()!='B'||stckque.length == 0)
                stckque.push_front('L');
            else{

                control.push_front(stckque.pop_front());
                control.push_front(stckque.pop_front());
                if(control.peek_front()=='L')
                    stckque.push_front('F');
                else if(control.peek_front()=='F')
                    stckque.push_front('R');
                else if(control.peek_front()=='R')
                    stckque.push_front('B');
                else
                    stckque.push_front('L');




            }}


    else if (solve_maze.can_move_forward()){

            StackQueue<char> control;
            solve_maze.move_forward();
            if(stckque.peek_front()!='B'||stckque.length == 0)
                stckque.push_front('F');
            else{

                control.push_front(stckque.pop_front());
                control.push_front(stckque.pop_front());
                if(control.peek_front()=='L')
                    stckque.push_front('R');
                else if(control.peek_front()=='F')
                    stckque.push_front('B');
                else if(control.peek_front()=='R')
                    stckque.push_front('L');
                else
                    stckque.push_front('F');




            }
    }
    else if (solve_maze.can_move_right()){

            StackQueue<char> control;
            solve_maze.move_right();
            if(stckque.peek_front()!='B'||stckque.length == 0)
                stckque.push_front('R');
            else{

                control.push_front(stckque.pop_front());
                control.push_front(stckque.pop_front());
                if(control.peek_front()=='L')
                    stckque.push_front('B');
                else if(control.peek_front()=='F')
                    stckque.push_front('L');
                else if(control.peek_front()=='R')
                    stckque.push_front('F');
                else
                    stckque.push_front('R');




            }
    }
    else if (solve_maze.can_move_back()){

            StackQueue<char> control;
            solve_maze.move_back();
            if(stckque.peek_front()!='B'||stckque.length == 0)
                stckque.push_front('B');
            else{

                control.push_front(stckque.pop_front());
                control.push_front(stckque.pop_front());
                if(control.peek_front()=='L')
                    stckque.push_front('L');
                else if(control.peek_front()=='F')
                    stckque.push_front('F');
                else if(control.peek_front()=='R')
                    stckque.push_front('R');
                else
                    stckque.push_front('B');

            }
    }
}

cout << "SQ: ";
stckque.print_elements();
cout<<endl;
solve_maze.print_state();
cout<< "Maze is solved. "   << endl;
cout<<endl;
cout<<endl;

cout<< "Second Pass: "   << endl;

while(solve_maze2.is_solved()!= true){
    cout << "SQ: ";
    stckque.print_elements();
    cout<<endl;
    solve_maze2.print_state();
    cout<<endl;
    char temp;
    temp = stckque.pop_rear();


    if(temp=='L')
        solve_maze2.move_left();
    else if(temp=='R')
        solve_maze2.move_right();
    else if(temp=='F')
        solve_maze2.move_forward();
    else
        solve_maze2.move_back();

    }



cout << "SQ: ";
stckque.print_elements();
cout<<endl;
solve_maze2.print_state();
cout<< "Maze is solved. "   << endl;
return 0;
 }
