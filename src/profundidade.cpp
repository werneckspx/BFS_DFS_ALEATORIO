#include "profundidade.hpp"
#include "pilha.hpp"

void read2() {
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

    Pilha f;
	Item posicao;
    FPVazia(&f);
    posicao.x =0;
    posicao.y =0;

    if (!input_file.is_open())
    {
        cout << "Nao foi possivel abrir o arquivo" << filename << " " << endl;
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
                print(mat);
                profundidade(mat, mat_guardar);
                
            }
        }
    }
    if (!(decisao))
    {
        print(mat);
        profundidade(mat, mat_guardar);
    }
    input_file.close();
    
}

void print(vector<vector<string>> mat) {
    for (int i= 0; i < (int)mat.size(); i++) {
        for (int j=0; j< (int)mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void profundidade(vector<vector<string>> mat, vector<vector<string>> mat_guardar) {
    Pilha p;
	Item posicao;
    FPVazia(&p);
    posicao.x =0;
    posicao.y =0;
    string comparacao;
    Item posicao_nova_busca;
    bool andou = false;
    int contador = 0;
    int contador_while = 0;
    int casas_percorridas = 0;

    //clock_t start = clock();
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    
    Push(&p, posicao);
    mat[posicao.x][posicao.y] = "0";
    //print(mat);

    do {
        contador_while++;
        //cout << endl << "============== CONTADOR " << contador_while << " ===============" << endl;
        andou = false;
        //full baixo
        if (posicao.x != mat.size()-1 && andou == false) {
            if (mat[posicao.x+1][posicao.y] == "1" || mat[posicao.x+1][posicao.y] == "*" || mat[posicao.x+1][posicao.y] == "?") {
                    //cout << endl << "vou pra baixo" << endl;
                    casas_percorridas ++;
                    posicao.x = posicao.x+1;
                    posicao.y = posicao.y;
                    comparacao = mat[posicao.x][posicao.y];

                    if(mat[posicao.x][posicao.y]=="*") {
                        casas_percorridas = 0;
                    //cout<<"Voltando a posicao inicial"<<endl;
                    mat_guardar[posicao.x][posicao.y]="1";
                    while (p.top!=p.base)
                    {
                        Pop(&p,&posicao);
                    }
                    posicao.x=0;
                    posicao.y=0;
                    Push(&p,posicao);
                    for (int i = 0; i < (int)mat.size(); i++)
                    {
                        for (int j = 0; j < (int)mat[i].size(); j++)
                        {
                            mat[i][j]=mat_guardar[i][j];
                        }
                    }
                }

                    Push(&p, posicao);
                    mat[posicao.x][posicao.y] = "0";
                    //print(mat);
                    //PImprime(&p);
                    andou = true;
            }
        }
        //full direita
        if (posicao.y != mat.size()-1 && andou == false) {
            if (mat[posicao.x][posicao.y+1] == "1" || mat[posicao.x][posicao.y+1] == "*" || mat[posicao.x][posicao.y+1] == "?") {
                //cout << endl << "vou pra direita" << endl;
                casas_percorridas ++;
                posicao.x = posicao.x;
                posicao.y = posicao.y+1;
                comparacao = mat[posicao.x][posicao.y];

                if(mat[posicao.x][posicao.y]=="*") {
                    //cout<<"Voltando a posicao inicial"<<endl;
                    casas_percorridas = 0;
                    mat_guardar[posicao.x][posicao.y]="1";
                    while (p.top!=p.base)
                    {
                        Pop(&p,&posicao);
                    }
                    posicao.x=0;
                    posicao.y=0;
                    Push(&p,posicao);
                    for (int i = 0; i < (int)mat.size(); i++)
                    {
                        for (int j = 0; j < (int)mat[i].size(); j++)
                        {
                            mat[i][j]=mat_guardar[i][j];
                        }
                    }
                }

                Push(&p, posicao);
                mat[posicao.x][posicao.y] = "0";
                //print(mat);
                //PImprime(&p);
                andou = true;
            }
        }
        //full cima
        if ((posicao.x != 0 && andou == false)) {
            if (mat[posicao.x-1][posicao.y] == "1" || mat[posicao.x-1][posicao.y] == "*" || mat[posicao.x-1][posicao.y] == "?") {
                //cout << endl << "vou pra cima" << endl;
                casas_percorridas ++;
                posicao.x = posicao.x -1;
                posicao.y = posicao.y;
                comparacao = mat[posicao.x][posicao.y];

                if(mat[posicao.x][posicao.y]=="*") {
                    //cout<<"Voltando a posicao inicial"<<endl;
                    casas_percorridas = 0;
                    mat_guardar[posicao.x][posicao.y]="1";
                    while (p.top!=p.base)
                    {
                        Pop(&p,&posicao);
                    }
                    posicao.x=0;
                    posicao.y=0;
                    Push(&p,posicao);
                    for (int i = 0; i < (int)mat.size(); i++)
                    {
                        for (int j = 0; j < (int)mat[i].size(); j++)
                        {
                            mat[i][j]=mat_guardar[i][j];
                        }
                    }
                }

                Push(&p, posicao);
                mat[posicao.x][posicao.y] = "0";
                //print(mat);
                //PImprime(&p);
                andou = true;
            }
        }
        //full esquerda
        if (posicao.y != 0 && andou == false) {
            if (mat[posicao.x][posicao.y -1] == "1" || mat[posicao.x][posicao.y -1] == "*" || mat[posicao.x][posicao.y -1] == "?") {
                //cout << endl << "vou pra esquerda" << endl;
                casas_percorridas ++;
                posicao.x = posicao.x;
                posicao.y = posicao.y-1;
                comparacao = mat[posicao.x][posicao.y];

                if(mat[posicao.x][posicao.y]=="*") {
                    //cout<<"Voltando a posicao inicial"<<endl;
                    casas_percorridas = 0;
                    mat_guardar[posicao.x][posicao.y]="1";
                    while (p.top!=p.base)
                    {
                        Pop(&p,&posicao);
                    }
                    posicao.x=0;
                    posicao.y=0;
                    Push(&p,posicao);
                    for (int i = 0; i < (int)mat.size(); i++)
                    {
                        for (int j = 0; j < (int)mat[i].size(); j++)
                        {
                            mat[i][j]=mat_guardar[i][j];
                        }
                    }
                }

                Push(&p, posicao);
                mat[posicao.x][posicao.y] = "0";
                //print(mat);
                //PImprime(&p);
                andou = true;
            }
        }
        //beco sem saída
        if (andou == false && beco_sem_saida(mat, posicao.x, posicao.y) == true)  { 
                contador++;
                Pop(&p, &posicao_nova_busca);
                //PImprime(&p);
                //cout << endl << "posição nova [" << posicao_nova_busca.x << "][" << posicao_nova_busca.y << "]" << endl;
                posicao.x = posicao_nova_busca.x;
                posicao.y = posicao_nova_busca.y;
                andou = true;
        }
        if (comparacao == "?") {
            cout << endl << endl << endl << "======================================================================================" << endl;
            cout << endl << endl << "ENCONTREI A INTERROGAÇÃO NA POSIÇÃO [" << posicao.x << "][" << posicao.y << "]" << "!" << endl;
            cout << "CASAS PERCORRIDAS " << casas_percorridas;
            mat[posicao.x][posicao.y] = "X";
            //print(mat);
            //clock_t end = clock();
            chrono::steady_clock::time_point end= chrono::steady_clock::now();
            chrono::duration<double> elapsed_seconds = chrono::duration_cast<chrono::duration<double>>(end - begin);
            //double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
            
            cout << endl << "A BUSCA EM PROFUNDIDADE DEMOROU: " << elapsed_seconds.count() << " SEGUNDOS PARA ENCONTRAR A '?'" << endl;
            cout << endl << "======================================================================================" << endl << endl << endl;
            break;
        }
        //usleep(800000);
        //system("clear");
    } while(comparacao != "?");
    print(mat);
}

bool beco_sem_saida(vector<vector<string>> mat, int i, int j) {
    //meio
    if ((i > 0 && i < mat.size()-1) && (j > 0 && j < mat.size()-1)) {
        if ((mat[i+1][j] == "0" || mat[i+1][j] == "#") && (mat[i][j+1] == "0" || mat[i][j+1] == "#") && (mat[i-1][j] == "0" || mat[i-1][j] == "#") && (mat[i][j+1] == "0" || mat[i][j+1] == "#")) {
            return true;
        }
    }
    //extremo superior esquerdo
    else if (i == 0 && j == 0) {
        if ((mat[i+1][j] == "0" || mat[i+1][j] == "#") && (mat[i][j+1] == "0" || mat[i][j+1] == "#")) {
            return true;
        }
    }
    //lateral esquerda
    else if ((i > 0) && (i < mat.size()-1) && (j == 0)) {
        if ((mat[i+1][j] == "0" || mat[i+1][j] == "#") && (mat[i-1][j] == "0" || mat[i-1][j] == "#") && (mat[i][j+1] == "0" || mat[i][j+1] == "#")) {
            return true;
        }
    }
    //extremo inferior esquerdo
    else if ((i == mat.size()-1) && (j == 0)) {
        if ((mat[i-1][j] == "0" || mat[i-1][j] == "#") && (mat[i][j+1] == "0" || mat[i][j+1] == "#")) {
            return true;
        }
    }
    //baixo no meio
    else if ((i == mat.size()-1) && (j > 0) && (j < mat.size()-1)) {
        if ((mat[i-1][j]=="0" || mat[i-1][j]=="#") && (mat[i][j-1] == "0" || mat[i][j-1] == "#") && (mat[i][j+1] == "0" || mat[i][j+1] == "#")) {
            return true;
        }
    }
    //extremo inferior direito
    else if ((i == mat.size()-1) && (j == mat.size()-1)) {
        if ((mat[i-1][j] == "0" || mat[i-1][j] == "#") && (mat[i][j-1] == "0" || mat[i][j-1] == "#")) {
            return true;
        }
    }
    //meio direito
    else if ((i > 0) && (i < mat.size()-1) && (j == mat.size()-1)) {
        if ((mat[i-1][j] == "0" || mat[i-1][j] == "#") && (mat[i][j-1] == "0" || mat[i][j-1] == "#") && (mat[i+1][j] == "0" || mat[i+1][j] == "#")) {
            return true;
        }
    }
    //extremo superior direito
    else if (i == 0 && j == mat.size()-1) {
        if ((mat[i+1][j] == "0" || mat[i+1][j] == "#") && (mat[i][j-1] == "0" || mat[i][j-1] == "#")) {
            return true;
        }
    }
    //meio superior
    else if ((i == 0) && (j > 0 && j < mat.size()-1)) {
        if ((mat[i+1][j] == "0" || mat[i+1][j] == "#") && (mat[i][j-1] == "0" || mat[i][j-1] == "#") && (mat[i][j+1] == "0" || mat[i][j+1] == "#")) {
            return true;
        }
    }
    else {
        return false;
    }
}


