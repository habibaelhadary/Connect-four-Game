#include <bits/stdc++.h>
using namespace std;
const int N=6;
const int M=7;
const int n_players = 2;
char marks[n_players] = {'X', 'O'};
char grid[N][M];
//This function clears the game structures
void grid_clear() {
for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
        grid[i][j]='.';
}
//This function prints the grid of Connect Four Game as the game progresses
void print_grid() {
	for (int i = 0; i< n_players; i++) {
        cout << "Player " << i+1 << ": " << marks[i] << "  ";
        if (i < n_players-1)
            cout << "vs  ";
	}
	cout << "\n";
	cout << "--";
    for (int i = 0; i < M; cout << "---", i++);
    cout << "--\n";
    for (int i = 0; i < N; i++) {
        cout << "|  ";
        for (int j = 0; j < M; j++)
            cout << grid[i][j] << "  ";
        cout << "|\n";
        cout << "--";
        for (int i = 0; i < M; cout << "---", i++);
        cout << "--\n";
    }
}
//This function checks if given cell is empty or not
bool check_empty(int i) {
      return (grid[0][i]=='.');
}
//This function checks if given position is valid or not
bool check_valid_column(int i) {
return (i>=0&&i<=6);
}

//This function reads a valid position input
void read_input(int &i) {
    cout << "Enter the column index: ";
    cin >> i;
     while (!check_valid_column(i) || !check_empty(i)) {
        cout << "Enter a valid column index: ";
        cin >> i;
    }
}
//This function sets the given mark to the given column
void set_cell(int i, char mark) {
    for(int j=N-1;j>=0;j--)
        if(grid[j][i]=='.'){
           grid[j][i]=mark;
           break;
        }

}
//This function checks if the game has a win state or not
bool check_win() {
    for(int i=N-1;i>=0;i--){
        for(int j=0;j<M-3;j++)
         if(grid[i][j]==grid[i][j+1]&&grid[i][j+1]==grid[i][j+2]&&grid[i][j+2]==grid[i][j+3]&&grid[i][j]!='.')
             return true;
        }

        for(int j=0;j<M;j++)
             for(int i=N-1;i>=3;i--)
                if(grid[i][j]==grid[i-1][j]&&grid[i-1][j]==grid[i-2][j]&&grid[i-2][j]==grid[i-3][j]&&grid[i][j]!='.')
                   return true;
        for(int i=3;i<M;i++){
            int row=0;
            while(row+3<N){
              if(grid[row][i]==grid[row+1][i-1]&&grid[row+1][i-1]==grid[row+2][i-2]&&grid[row+2][i-2]==grid[row+3][i-3]&&grid[row][i]!='.')
                 return true;
              row++;
            }
        }
        for(int i=0;i<M-3;i++){
           int col=i;
           int row=0;
           while(row+3<N){
              if(grid[row][col]==grid[row+1][col+1]&&grid[row+1][col+1]==grid[row+2][col+2]&&grid[row+2][col+2]==grid[row+3][col+3]&&grid[row][col]!='.')
                 return true;
              row++;
          }
        }

      return false;
}
//This function checks if the game has a tie state or not for the given mark
bool check_tie_player(char mark) {
    int x=0,y=0,zright=0,zleft=0;
    for(int i=N-1;i>=0;i--)
        for(int j=0;j<M-3;j++)
         if(grid[i][j]==mark||grid[i][j+1]==mark||grid[i][j+2]==mark||grid[i][j+3]==mark)
            x++;
         for(int j=0;j<M;j++)
             for(int i=N-1;i>=3;i--)
               if(grid[i][j]==mark||grid[i-1][j]==mark||grid[i-2][j]==mark||grid[i-3][j]==mark)
                  y++;
         for(int i=3;i<M;i++){
            int row=0;
            while(row+3<N){
             if(grid[row][i]==mark||grid[row+1][i-1]==mark||grid[row+2][i-2]==mark||grid[row+3][i-3]==mark)
                 zright++;
              row++;
              }
        }
        for(int i=0;i<M-3;i++){
            int col=i;
            int row=0;
            while(row+3<N){
              if(grid[row][col]==mark||grid[row+1][col+1]==mark||grid[row+2][col+2]==mark||grid[row+3][col+3]==mark)
                 zleft++;
              row++;
              }
        }
        if(x>=24&&y>=21&&(zleft+zright)>=24)
            return true;
         return false;
}
//This function checks if the game has a tie state or not
bool check_tie() {
    bool all_tie = true;
    for (int i = 0; i < n_players; i++)
        if (!check_tie_player(marks[i]))
            all_tie = false;
    return all_tie;
}
//MAIN FUNCTION
void play_game() {
    cout << "Connect Four Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";
    int player = 0;
    while(true){
        //Prints the grid
        print_grid();
        //Read an input from the player
        cout << "Player " << marks[player] << " is playing now\n";
        int i;
		read_input(i);
        //Set the input position with the mark
        set_cell(i, marks[player]);
        //Check if the state of the grid has a win state
        if (check_win()) {
            //Prints the grid
            print_grid();
            //Announcement of the final statement
            cout << "Congrats, Player " << marks[player] << " is won!\n";
            break;
        }
        //Check if the state of the grid has a tie state
        if (check_tie()) {
            //Prints the grid
            print_grid();
            //Announcement of the final statement
            cout << "Woah! That's a tie!\n";
            break;
        }
        //Player number changes after each turn
		player=(player+1)%n_players;
    }
}
int main() {

    while (true){
    	grid_clear();
    	play_game();
    	char c;
    	cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
    }

}
