#include "largura.hpp"
void read()
{
    vector<vector<string>> mat;
    vector<vector<string>> mat_guardar;
    string filename("dataset/input.data");
    ifstream input_file(filename, ios::in);
    string line;
    vector<string> n;
    vector<int> aux;
    int tam;
    bool decisao = false;
    srand(time(NULL));
    string num;

    Fila f;
	Item posicao;
    FFVazia(&f);
    posicao.x =0;
    posicao.y =0;
    Enfileira(&f, posicao);

    if (!input_file.is_open())
    {
        cout << "Nao foi possivel abrir o arquivo"
             << filename << " " << endl;
    }
    int cont = 0;
    while (!input_file.eof())
    {
        while (getline(input_file, line, '\n'))
        {
            istringstream ln(line);

            if (cont == 0)
            {
                cont++;
                while (ln >> num)
                {
                    aux.push_back(atoi(num.c_str()));
                }
                tam = aux[0];
                n.clear();
                continue;
            }
            else if (line.size() > 1)
            {
                decisao = false;
                while (ln >> num)
                {
                    n.push_back(num);
                }
                mat.push_back(n);
                mat_guardar.push_back(n);
                line.clear();
                n.clear();
            }
            else
            {
                decisao = true;
                movimento(mat,mat_guardar,0,0,f);  
            }
        }
    }
    if (!(decisao))
    {
        movimento(mat,mat_guardar,0,0,f);  
    }
    input_file.close();
    
}

void imprimindo(vector<vector<string>> mat)
{

    for (int i = 0; i < (int)mat.size(); i++)
    {
        for (int j = 0; j < (int)mat[i].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void movimento(vector<vector<string>> mat,vector<vector<string>> mat_guardar, int i, int j, Fila f){
    /*0.0 0.1 0.2 0.3
      1.0 1.1 1.2
      2.0 2.1
      3.0 
    */
    Item posicao;
    int contador_auxiliar=0,casasPercorridas=0;
    //FImprime(&f);
    imprimindo(mat);

    //clock_t start = clock();
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    while (mat[i][j]!="?")
    {
        
        Block *aux;

        if(f.first == f.last){
            printf("FILA VAZIA!\n");
        }else{
        
        aux = f.first->prox;
        posicao = aux->data;
        
        }
        //cout<<"Posicao inicial: "<<posicao.x<<posicao.y<<endl;
        i=posicao.x;
        j=posicao.y;

        if(mat[i][j]=="*")
        {
            //cout<<"Voltando a posicao inicial"<<endl;
            mat_guardar[i][j]="1";
            while (f.first!=f.last)
            {
                Desenfileira(&f,&posicao);
            }
            i=0;
            j=0;
            Enfileira(&f,posicao);
            for (int i = 0; i < (int)mat.size(); i++)
            {
                for (int j = 0; j < (int)mat[i].size(); j++)
                {
                    mat[i][j]=mat_guardar[i][j];
                }
            }
            casasPercorridas=0;
        }

        if (mat[i][j]=="?")
        {
            //clock_t end = clock();
            chrono::steady_clock::time_point end= chrono::steady_clock::now();
            chrono::duration<double> elapsed_seconds = chrono::duration_cast<chrono::duration<double>>(end - begin);
            //double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
            cout << endl << endl << endl << "======================================================================================" << endl;
            cout << "CASAS PERCORRIDAS " << casasPercorridas;
            cout << endl << "A BUSCA POR LARGURA DEMOROU: " << elapsed_seconds.count() << " SEGUNDOS PARA ENCONTRAR A '?'" << endl;
            cout << endl << "=======================================================================================" << endl << endl << endl;
            break;
        }
        
        if (i==0 && j==0)
        {
            //direita
            j=j+1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            j=j-1;
            //diagona direita baixo
            i=i+1;
            j=j+1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i-1;
            j=j-1;
            //baixo
            i=i+1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i-1;
        }else if(j+1==mat[0].size() && i==0){
            //baixo
            i=i+1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i-1;
            // diagonal esquerda baixo
            i=i+1;
            j=j-1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i-1;
            j=j+1;
            //esquerda
            j=j-1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            j=j+1;
        }else if(i+1==mat[0].size() && j==0){
            //cima
            i=i-1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i+1;
            //direita
            j=j+1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            j=j-1;
            //diagona direita cima
            i=i-1;
            j=j+1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i+1;
            j=j-1;
        }else if(i+1==mat[0].size() && j+1==mat[0].size()){
            //esquerda
            j=j-1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            j=j+1;
            //cima
            i=i-1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i+1;
            // diagonal esquerda cima
            i=i-1;
            j=j-1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i+1;
            j=j+1;
        }else if (j+1==mat[0].size())
        {
            //baixo
            i=i+1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i-1;
            // diagonal esquerda baixo
            i=i+1;
            j=j-1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i-1;
            j=j+1;
            //esquerda
            j=j-1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            j=j+1;
            // diagonal esquerda cima
            i=i-1;
            j=j-1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i+1;
            j=j+1;
            //cima
            i=i-1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i+1;
        }else if (i+1==mat[0].size())
        {
            //diagona direita cima
            i=i-1;
            j=j+1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i+1;
            j=j-1;
            //direita
            j=j+1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            j=j-1;
            //esquerda
            j=j-1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            j=j+1;
            // diagonal esquerda cima
            i=i-1;
            j=j-1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i+1;
            j=j+1;
            //cima
            i=i-1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i+1;
        }else if(i==0){
            //direita
            j=j+1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            j=j-1;
            //esquerda
            j=j-1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            j=j+1;
            //baixo
            i=i+1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i-1;
            //diagona direita baixo
            i=i+1;
            j=j+1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i-1;
            j=j-1;
            // diagonal esquerda baixo
            i=i+1;
            j=j-1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i-1;
            j=j+1;
        }else if(j==0){
            //direita
            j=j+1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            j=j-1;
            //baixo
            i=i+1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i-1;
            //cima
            i=i-1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i+1;
            //diagona direita baixo
            i=i+1;
            j=j+1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i-1;
            j=j-1;
            //diagona direita cima
            i=i-1;
            j=j+1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i+1;
            j=j-1;
        }else{
            //esquerda
            j=j-1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            j=j+1;
            // diagonal esquerda cima
            i=i-1;
            j=j-1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i+1;
            j=j+1;
            //cima
            i=i-1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i+1;
            //diagona direita cima
            i=i-1;
            j=j+1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i+1;
            j=j-1;
            //direita
            j=j+1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            j=j-1;
            //diagona direita baixo
            i=i+1;
            j=j+1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i-1;
            j=j-1;
            //baixo
            i=i+1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i-1;
            // diagonal esquerda baixo
            i=i+1;
            j=j-1;
            movimento_x_y(mat,&i,&j,&f,posicao);
            i=i-1;
            j=j+1;

        }
    
        mat[i][j]="0";
        casasPercorridas++;
        
        //imprimindo(mat);
        //usleep(300000);
        //system("clear");
        //FImprime(&f);
        Desenfileira(&f, &posicao);
        //imprimindo(mat);
        
    }
    imprimindo(mat);
    
}

void movimento_x_y(vector<vector<string>> &mat, int *i, int *j, Fila *f,Item posicao){
            if(mat[*i][*j]=="#"){
                //cout<<"Parade encontrada"<<endl;
            }else if(mat[*i][*j]!="X"){
                posicao.x=*i;
                posicao.y=*j;
                if(mat[posicao.x][posicao.y]!="?" && mat[posicao.x][posicao.y]!="*" && mat[posicao.x][posicao.y]!="0"){
                    mat[posicao.x][posicao.y]="X";
                    Enfileira(f,posicao);
                }else if (mat[posicao.x][posicao.y]=="?")
                {
                    Enfileira(f,posicao);
                }else if (mat[posicao.x][posicao.y]=="*")
                {
                    Enfileira(f,posicao);
                }
                
            }
}
