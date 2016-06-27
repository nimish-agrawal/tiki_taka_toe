



class Board{
	
	Board currentState(){}    // return current board configuration
	
	void fillpos(int x, int y, Player player){}         // fills position on board
	
	void clearpos(int x,int y){}          // Clear position
	
}







class Main{

Board best_move;                         //Stores the next best move to make;


int score(Player player , Board board)      //Recursive algo wich stores the best move to make in best_move and returns best score
{
   if(board.currentState() == end_state)
   {
      if(end_state == draw)
      { 
	     return 0;
	  }	  
      else if (player=='me')         //Comp's previous move led to an end which is not a draw. Therefore comp made a winning move
	  {
	     return -10;
	  }
	  else if(player == 'comp')      //I made a winning move
	  {
		  return 10;
	  }
   }
  
   List<int> SSL = new ArrayList();  // SSL = States_Score_List
   List<Board> ML = new ArrayList(); //ML = Moves_list
   
   
    
   
   for(i=0;i<3;i++)
   {
	   for(j=0;j<3;j++)
	   {
		   if(board.pos(i,j)=='FREE')
		   {
			   board.fillpos(i,j,player);
			   SSL.add(score(Opponent_Of(player),board.currentState()));
			   ML.add(board.currentState());
			   board.clearpos(i,j);
		  }
	   }
   }
   
   
   int best_score, best_score_index;
   if(player=='me')
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


int main(){}


}