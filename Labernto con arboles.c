#include <stdio.h>
#include<stdbool.h>

  struc BinaryTree
  {

        
    struc BinaryTree parent; // parent of node
  	struc BinaryTree left, center ,right; // children of node
  }
	struc BinaryTree* newBinaryTree(BinaryTree padre)
	// post: constructor that generates an empty node
	{
	  struct BinaryTree* node = (struct BinaryTree*)malloc(sizeof(struct node));
		node->parent = padre; 
		node->left = null;
		node->center = null;
		node->right = null;
		return(node);
	}
        
    }
    
    BinaryTree *raiz = newBinaryTree(null); 
    void girar (int grados){
        ;
    }
    boolean revisar(){
        return true;
    }
    void avanzar (){
        ;
    }
    void regresar (BinaryTree ** nodo){
        int[3] op ;
        if (*nodo->left == null) op[0] = 0; else op[0] = 1;
        if (*nodo->center == null) op[1] = 0; else op[1] = 1;
        if (*nodo->right == null) op[2] = 0; else op[2] = 1;
        int cont = 0;
        for(int i =0;i < 3 ;i++){
            if (op[i] == 1){
                cont++;
            }
        }
        if (cont>1){
            int grados = 90;
            for (int i = 0; i<3; i++){
                if (cont > 1){
                    if (op[i] == 1){
                        op[i] = 0;
                        cont = 1;
                    } else {
                        avanzar();
                        girar(grados);
                        avanzar();
                        switch (i){
                            case 0:moverse(*nodo->left); break;
                            case 1:moverse(*nodo->center); break;
                            case 2:moverse(*nodo->right); break;
                        }
                    }
                }
                grados = grados - 90;
            }
            
        } else {
            avanzar();
            int grados = 90;
            for (int i = 0; i<3; i++){
                if (op[i] == 1) {
                    girar(grados);
                }
                grados = grados - 90;
            }
            regresar(*nodo->parent);
        }
        
    }
    void moverse(BinaryTree ** nodo){
        int grados = -90;
        int[3] op ;
        for (int i =0; i< 3; i++){
            op[i] = 0;
            girar(grados);
            if (revisar()){
                op[i] = 1;
            }
            girar(-1*grados);
            grados = grados + 90;
        }
        if (op[0] == 1) *nodo->left = newBinaryTree(nodo);
        if (op[1] == 1) *nodo->center = newBinaryTree(nodo);
        if (op[2] == 1) *nodo->right = newBinaryTree(nodo);
        grados = -90;
        if ((op[0]==1) || (op[1]==1) || (op[2]==1)){
            for (int i =0;i < 3; i++ ){
                if (op[i] == 1){
                    girar(grados);
                    avanzar();
                    BinaryTree *siguiente = null;
                    switch (i){
                        case 0: *siguiente = *nodo->left; break;
                        case 1: *siguiente = *nodo->center; break;
                        case 2: *siguiente = *nodo->right; break;
                    } 
                    moverse(*siguiente);
                    grados = grados + 90;
                }  
            }
        } else {
            girar(180);
            regresar(*nodo->parent);
        }
                
    }
    int main (String[] Args){
    }