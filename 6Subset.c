#include <stdio.h> 
#include <stdlib.h> 

  

static int total_nodes; 
// prints subset found 

void printSubset(int A[], int size) 
{ 

    for(int i = 0; i <= size; i++) 

    { 

        printf("%*d",5, A[i-1]); 

    } 

 
} 

  
void subset_sum(int s[], int t[], 

                int s_size, int t_size, 

                int sum, int ite, 

                int const target_sum) 
{ 

    total_nodes++; 

    if( target_sum == sum ) 

    { 

        // We found subset 

        printSubset(t, t_size); 

        // Exclude previously added item and consider next candidate 

        subset_sum(s, t, s_size, t_size-1, sum - s[ite], ite + 1, target_sum); 

        return; 

    } 

    else

    { 

        // generate nodes along the breadth 

        for( int i = ite; i < s_size; i++ ) 

        { 

            t[t_size] = s[i]; 

            // consider next level node (along depth) 

            subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum); 

        } 

    } 
} 

  
// Wrapper to print subsets that sum to target_sum 
// input is weights vector and target_sum 

void generateSubsets(int s[], int size, int target_sum) 
{ 

    int *tuplet_vector = (int *)malloc(size * sizeof(int)); 

  

    subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum); 

  

    free(tuplet_vector); 
} 

  

int main() 
{ 
    int n,s;
    printf("enter the N And S Value");
    scanf("%d",&n);
    scanf("%d",&s);
    int weights[20];
    int i;
    printf("Enter The weight Values");
    for(i=0;i<n;i++)
    {
        scanf("%d",&weights[i]);
    }
    
    generateSubsets(weights, n,s); 

   /* printf("Nodes generated %dn", total_nodes); */

    return 0; 
} 
