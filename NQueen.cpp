/*
 * NQueen.cpp
 *
 *  Created on: Nov 4, 2017
 *      Author: nehal
 */

#include <iostream>
#include <cmath>
using namespace std;


bool check(int q[], int c){
	for(int i = 0; i < c ; i++){
		if(q[i] == q[c])
			return false;
		if( abs(q[i]-q[c]) == c - i )
			return false;
	}
	return true;
}

int modularQueen(int n){
	int* q = new int[n];
	int solutionNum = 0;
	int column = 0;

	while (column >= 0){
		if (column == n-1){
			solutionNum++;
			column--; //Solution found now backtrack everything
		}
		else
			q[++column] = -1; //starts at 1 (this is what increments the column)

			while (column >= 0){
				q[column]++;

				if(q[column] == n) //outside the board
					column--; //backtrack
				else if(check(q, column)){ //if queen placed checks out, break the loop
					break;
				}
			}
	}
	delete []q;
	return solutionNum;
}

int main(){
	int n;
	cout<<"Give me an integer: ";
	cin>>n;

	for(int i = 1; i <= n ; i++)
		cout<<i<<". There are "<<modularQueen(i)<<" solutions to the " << i << " queens problem"<<endl;

	return 0;
}

