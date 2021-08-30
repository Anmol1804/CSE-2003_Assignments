#include<iostream>
using namespace std;

//Setting the maximum size of stack to be 100
const int size = 50;

//creating a stack class
class stack{
    int st[size];
    int top;
        
    public:
		//Default Constructor to initialize top of stack
        stack(){
		    top = -1;
        }
                
        // func to push element to stack
        void push(int num){
            if(top == size-1)
                return;
                        
			top++;      
            st[top] = num;                                
        }
                
        //func to pop element from stack    
        int pop(){
            if(top == -1)
                return NULL;
            else{
				int num = st[top];
				top--;
				return num;
            }
        }
        
        //func to keep count
        int getCount(){
            return (top+1);
        }
}; 

int main(){
    //Creating stack object s1 & s2 for Player 1 & Player 2 repsectively
    stack s1, s2;
    int n, i, num, number;
    int n1, n2;
        
    //Asking user for count of numbers to give the players
    cout<<"Enter the count of numbers to be given to players: ";
    cin>>n;
        
    //Pushing elements onto player 1 stack
    cout<<"\nEnter player #1 numbers to push into stack: ";
    for(i=0; i<n; ++i){
        cin>>num;    
        s1.push(num);
    }
        
    //Pushing elements onto player 1 stack
    cout<<"\nEnter player #2 numbers to push into stack: ";
    for(i=0; i<n; ++i){
        cin>>num;       
        s2.push(num);
    }
    
    // do-while loop to check
    do{
        //pop number from the top of player 1 stack
        n1 = s1.pop();
                
        //Checking if player 1 stack is empty 
        if(s1.getCount() == 0 || n1 == NULL){
            cout<<"\nPlayer 1 is the winner!"<<endl;
            return 0;
        }
        
        //pop number from the top of player 1 stack
        n2 = s2.pop();
                
        //Checking if player 2 stack is empty 
        if(s2.getCount() == 0 || n2 == NULL){
            cout<<"\nPlayer 2 is the winner!"<<endl;
            return 0;       
        }
                
        //Checking if player 1 stack popped number is greater than player 2 stack popped number
        if(n1 > n2){
            for(i=n2; i<n1; ++i){
            //Remove number from the top of player 1 stack
                number = s1.pop();
                                
            //Checking if player 1 stack is empty 
            	if(s1.getCount() == 0 || number == NULL){
                    cout<<"\nPlayer 1 is the winner!"<<endl;
                    return 0;
                }                               
                                
            //pushing number on top of the player 2 stack
                s2.push(number);
            }
        }
                
        //Checking if player 2 stack popped number is greater than player 1 stack popped number
        else if(n2 > n1){
            for(i=n1; i<n2; ++i){
                //Remove number from the top of player 2 stack
                number = s2.pop();
                                
                //Checking if player 2 stack is empty 
                if(s2.getCount() == 0 || number == NULL){
                    cout<<"\nPlayer 2 is the winner!"<<endl;
                    return 0;
                }
                                
                //Adding number on top of the player 1 stack
                s1.push(number);
            }
        }               
    }while(true);   
}

