package practise;
import java.util.*;


public class addmatrix {
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int i , j ;
        int n = Integer.parseInt(args[0]);
        int a [][] = new int[n][n];
        int b [][] = new int[n][n];
        int c [][] = new int[n][n];
        System.out.println("Enter the matrix A ");
        for( i = 0 ; i < n ; i++){
            for( j = 0 ; j < n ; j++){
                a[i][j] = s.nextInt() ;

            }
        }
        System.out.println("Enter the matrix B ");
        for( i = 0 ; i < n ; i++){
            for( j = 0 ; j < n ; j++){
                b[i][j] = s.nextInt() ;
                
            }
        }
        System.out.println("Enter the matrix c ");
        for( i = 0 ; i < n ; i++){
            for( j = 0 ; j < n ; j++){
                c[i][j] = a[i][j] + b[i][j] ;
                
            }
        }
        System.out.println("The resultant is  ");
        for( i = 0 ; i < n ; i++){
            for( j = 0 ; j < n ; j++){
                System.out.print(C[i][j] + " ");
                
            }
            System.out.println();
        }



    }
}
