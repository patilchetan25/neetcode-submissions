class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        /* 
        I maintain three arrays. rows[i] stores the digits already seen 
        in row i, cols[i] stores digits seen in column i, and squares[i] 
        stores digits seen in each 3×3 box.
        Example : rows[0] = 000010100 (means row 0 contains digits 3 and 5.)

        */
        
        int row[9]={0};
        int col[9]={0};
        int sq[9]={0};

        // I visit every cell in the board.

        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                //Empty cells are ignored because they don't contain a digit.

                if(board[r][c]=='.') continue;

                /* 
                I convert the character digit into a bit position. 
                For example, digit 1 maps to bit 0, digit 2 maps to bit 1, 
                and digit 9 maps to bit 8.
                Example : '5' - '1' = 4
                
                */

                int val= board[r][c]-'1'; 

                /*
                To find the 3×3 box, I divide row and column by 3. 
                This gives me the box row and box column. 
                Since each box row contains 3 boxes, 
                I multiply the box row by 3 and add the box column
                (r / 3) * 3 + (c / 3)

                Example : r = 4, c = 7
                r/3 = 1
                c/3 = 2
                box = 1*3 + 2 = 5
                So the cell belongs to: squares[5]
                */



                /*
                I create a mask for the current digit. Then I use AND to check 
                if that bit is already set in the row, column, or box. If any of 
                them already contain this digit, the Sudoku is invalid.
                */


                if(row[r]&(1<<val) || 
                col[c]&(1<<val) || 
                sq[(r/3)*3+(c/3)]&(1<<val)){
                    return false;
                }

                /*
                After confirming the digit is not present, I mark it as seen 
                using OR. OR turns on the corresponding bit while keeping all 
                previous digits

                Example : Before:
                000010000   (5 exists)

                Add 7: 001000000

                After OR: 
                001010000   (5 and 7 exist)

                */


                row[r] |=(1<<val);
                col[c] |=(1<<val);
                sq[(r/3)*3+(c/3)] |=(1<<val);
            }
        }
        return true;
        
    }
};
