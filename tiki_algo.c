



class Board{
	
	char a[3][3];
	
	Board()
	{
		int i,j;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
				a[i][j] = 'b';
		}
		//clear the actual matrix
	}
	
	char pos(int i,int j)
	{
		if(a[i][j]=='b')
			return 'f';           // free
		return 'n';               // not free
	}

    bool checkrow(int i)
	{
		if(a[i][0]==a[i][1]&&a[i][1]==a[i][2])
			return true;
		return false;
	}

    bool checkcol(int j)
	{
		if(a[0][j]==a[1][j]&&a[1][j]==a[2][j])
			return true;
		return false;
	}

    bool checkdiags()
	{
		if((a[0][0]==a[1][1]&&a[1][1]==a[2][2])||(a[0][2]==a[1][1]&&a[1][1]==a[2][0]))
			return true;
		return false;
	}    
	
	char currentState(){
		   int i,j,b=1;                   //'b' => blank = 1; if 1, return n -> not end_state 
		   for(i=0;i<3;i++)
		   {
			   for(j=0;j<3;j++)
			   {
				   if(a[i][j]!='b')
				   {
					   b = 0;
					   break;
				   }
			   }
		   }
		   if(b==1)
		   {
			   return 'b';
		   }
		   if(checkrow(0) || checkrow(1) || checkrow(2) || checkcol(0)||checkcol(1)||checkcol(2)||checkdiags())
          	   return 'v';                                                   // 'v' = victory
           return 'n';                                                         // not end_state
	}                                                                    // return current board configuration
	
	void fillpos(int x, int y, char player){
		     if(player = 'm')
				 a[x][y] = 'x';                    // player is 'x';
			 else
 				 a[x][y] = 'o';                    // comp is 'o';
	}         // fills position on board
	
	void clearpos(int x,int y){
		     a[x][y] = 'b';
	}          // Clear position
	
	void 
	{
		
	}
	
}


class Move{
	int i,j;
	Move(int i,int j)
	{
		this.i = i;
		this.j = j;
	}
}


class Main{

Move best_move;                         //Stores the next best move to make;


char Opponent_Of(char player)
{
	if(player == 'm')
		return 'c';
	return 'm';
}

int score(char player , Board board)      //Recursive algo wich stores the best move to make in best_move and returns best score
{
   if(board.currentState() != 'n' )         // 'n' = not end_state 
   {
      if(board.currentState()=='d')         // 'd' = draw state
      { 
	     return 0;
	  }	  
      else if (player=='m')         //'m' = me. Comp's previous move led to an end which is not a draw. 
	  {                             // Therefore comp made a winning move
	     return -10;
	  }
	  else if(player == 'c')        //'c' = comp. I made a winning move
	  {
		  return 10;
	  }
   }
  
   List<int> SSL = new ArrayList();  // SSL = States_Score_List
   List<Move> ML = new ArrayList(); //ML = Moves_list
   
   
    
   
   for(i=0;i<3;i++)
   {
	   for(j=0;j<3;j++)
	   {
		   if(board.pos(i,j)=='f')    // if position is free
		   {
			   board.fillpos(i,j,player);
			   SSL.add(score(Opponent_Of(player),board));
			   Move m = new Move(i,j);
			   ML.add(m);
			   board.clearpos(i,j);
		   }
	   }
   }
   
   
   int best_score, best_score_index;
   if(player=='m')
   {
	   best_score = max(SSL);
   }
   else
   {
	   best_score = min(SSL);
   }
   best_score_index = SSL.getIndex(best_score);
   
   best_move = ML.get(best_score_index);      //keeps storing the best move in best_move. The bottom-most recursive stack element(the original fn call) will store the 
                                              // the best move to be performed
   return best_score;
   
}




int main(){
	Board board = new Board();
    
	while(board.current_state()!='n')
	{
		//when person clicks --update board with 'x' at that position
        score('c',board);
        //execute the best_move with 'o' at that position
	}


}

}