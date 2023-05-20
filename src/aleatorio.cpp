#include "aleatorio.hpp"

void read3() {
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


	Item2 posicao;
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
                randomico(mat, mat_guardar);
                
            }
        }
    }
    if (!(decisao))
    {
        randomico(mat, mat_guardar);
    }
    input_file.close();
    
}

void print1(vector<vector<string>> mat) {
    for (int i= 0; i < (int)mat.size(); i++) {
        for (int j=0; j< (int)mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void randomico(vector<vector<string>> mat, vector<vector<string>> mat_guardar) {
    Item2 posicao;
    posicao.x =0;
    posicao.y =0;
    string comparacao;
    int possivel_direcao;
    mat[posicao.x][posicao.y] = "0";
    print1(mat);
    bool achou = false;
    int casas_percorridas = 0;
    //clock_t start = clock();
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    do {
        possivel_direcao = rand()%8+1;
        //Ir pra cima
        if (possivel_direcao == 1 && posicao.x != 0 && mat[posicao.x-1][posicao.y] != "#" && mat[posicao.x-1][posicao.y] != "0") {
            //cout << endl << "Vou pra cima" << endl;
            comparacao = mat[posicao.x-1][posicao.y];
            casas_percorridas ++;
            
            if (comparacao == "?") {
                cout << endl << "============= ENCONTROU O '?' =============" << endl;
                mat[posicao.x-1][posicao.y] = "X";
                achou = true;
                //print1(mat);
                //clock_t end = clock();
                //double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
                chrono::steady_clock::time_point end= chrono::steady_clock::now();
                chrono::duration<double> elapsed_seconds = chrono::duration_cast<chrono::duration<double>>(end - begin);
                cout << endl << endl << "=======================================================================================" << endl;
                cout << endl << "A BUSCA RANDÔMICA DEMOROU: " << elapsed_seconds.count() << " SEGUNDOS PARA ENCONTRAR A '?'" << endl;
                cout << "CASAS PERCORRIDAS: " << casas_percorridas;
                cout << endl << "=======================================================================================" << endl << endl << endl;
                print1(mat);
            }
            else if (comparacao == "*") {
                ////cout << endl << "Encontrou um '*'" << endl <<"Voltando a posicao inicial" << endl;
                casas_percorridas = 0;
                mat_guardar[posicao.x-1][posicao.y]="1";
                posicao.x=0;
                posicao.y=0;
                for (int i = 0; i < (int)mat.size(); i++) {
                    for (int j = 0; j < (int)mat[i].size(); j++) {
                            mat[i][j]=mat_guardar[i][j];
                    }
                }
                mat[posicao.x][posicao.y] = "0";
            }
            else {
                posicao.x = posicao.x-1;
                mat[posicao.x][posicao.y] = "0";
                //print1(mat);
            }
        }
        //Ir pra direita
        else if (possivel_direcao == 2 && posicao.y != mat.size()-1 && mat[posicao.x][posicao.y+1] != "#" && mat[posicao.x][posicao.y+1] != "0") {
            //cout << endl << "Vou pra direita" << endl;
            casas_percorridas ++;
            comparacao = mat[posicao.x][posicao.y+1];

            if (comparacao == "?") {
                cout << endl << "========== ENCONTROU O '?' =========" << endl;
                mat[posicao.x][posicao.y+1] = "X";
                achou = true;
                ////print(mat);
                //clock_t end = clock();
                //double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
                chrono::steady_clock::time_point end= chrono::steady_clock::now();
                chrono::duration<double> elapsed_seconds = chrono::duration_cast<chrono::duration<double>>(end - begin);
                cout << endl << endl << "=======================================================================================" << endl;
                cout << endl << "A BUSCA RANDÔMICA DEMOROU: " << elapsed_seconds.count() << " SEGUNDOS PARA ENCONTRAR A '?'" << endl;
                cout << "CASAS PERCORRIDAS: " << casas_percorridas;
                cout << endl << "=======================================================================================" << endl << endl << endl;
                print1(mat);
            }
            else if (comparacao == "*") {
                //cout << endl << "Encontrou um '*'" << endl <<"Voltando a posicao inicial" << endl;
                casas_percorridas = 0;
                mat_guardar[posicao.x][posicao.y+1]="1";
                posicao.x=0;
                posicao.y=0;
                for (int i = 0; i < (int)mat.size(); i++) {
                    for (int j = 0; j < (int)mat[i].size(); j++) {
                            mat[i][j]=mat_guardar[i][j];
                    }
                }
                mat[posicao.x][posicao.y] = "0";
            }
            else {
                posicao.y = posicao.y+1;
                mat[posicao.x][posicao.y] = "0";
                //print1(mat);
            }
        }
        //Ir pra baixo
        else if (possivel_direcao == 3 && posicao.x != mat.size()-1 && mat[posicao.x+1][posicao.y] != "#" && mat[posicao.x+1][posicao.y] != "0") {
            //cout << endl << "Vou pra baixo" << endl;
            casas_percorridas ++;
            comparacao = mat[posicao.x+1][posicao.y];

            if (comparacao == "?") {
                cout << endl << "=========== ENCONTROU O '?' ===========" << endl;
                mat[posicao.x+1][posicao.y] = "X";
                achou = true;
                ////print(mat);
                //clock_t end = clock();
                //double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
                chrono::steady_clock::time_point end= chrono::steady_clock::now();
                chrono::duration<double> elapsed_seconds = chrono::duration_cast<chrono::duration<double>>(end - begin);
                cout << endl << endl << "=======================================================================================" << endl;
                cout << endl << "A BUSCA RANDÔMICA DEMOROU: " << elapsed_seconds.count() << " SEGUNDOS PARA ENCONTRAR A '?'" << endl;
                cout << "CASAS PERCORRIDAS: " << casas_percorridas;
                cout << endl << "=======================================================================================" << endl << endl << endl;
                print1(mat);
            }
            else if (comparacao == "*") {
                //cout << endl << "Encontrou um '*'" << endl <<"Voltando a posicao inicial" << endl;cout<<"Voltando a posicao inicial"<<endl;
                casas_percorridas = 0;
                mat_guardar[posicao.x+1][posicao.y]="1";
                posicao.x=0;
                posicao.y=0;
                for (int i = 0; i < (int)mat.size(); i++) {
                    for (int j = 0; j < (int)mat[i].size(); j++) {
                            mat[i][j]=mat_guardar[i][j];
                    }
                }
                mat[posicao.x][posicao.y] = "0";
            }
            else {
                posicao.x = posicao.x+1;
                mat[posicao.x][posicao.y] = "0";
                //print1(mat);
            }
        }
        //Ir pra esquerda
        else if (possivel_direcao == 4 && posicao.y != 0 && mat[posicao.x][posicao.y-1] != "#" && mat[posicao.x][posicao.y-1] != "0") {
            //cout << endl << "Vou pra esquerda" << endl;
            casas_percorridas ++;
            comparacao = mat[posicao.x][posicao.y-1];

            if (comparacao == "?") {
                cout << endl << "ENCONTROU O '?'" << endl;
                mat[posicao.x][posicao.y-1] = "X";
                achou = true;
                ////print(mat);
                //clock_t end = clock();
                //double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
                chrono::steady_clock::time_point end= chrono::steady_clock::now();
                chrono::duration<double> elapsed_seconds = chrono::duration_cast<chrono::duration<double>>(end - begin);
                cout << endl << endl << "=======================================================================================" << endl;
                cout << endl << "A BUSCA RANDÔMICA DEMOROU: " << elapsed_seconds.count() << " SEGUNDOS PARA ENCONTRAR A '?'" << endl;
                cout << "CASAS PERCORRIDAS: " << casas_percorridas;
                cout << endl << "=======================================================================================" << endl << endl << endl;
                print1(mat);
            }
            else if (comparacao == "*") {
                //cout << endl << "Encontrou um '*'" << endl <<"Voltando a posicao inicial" << endl;
                casas_percorridas = 0;
                mat_guardar[posicao.x][posicao.y-1]="1";
                posicao.x=0;
                posicao.y=0;
                for (int i = 0; i < (int)mat.size(); i++) {
                    for (int j = 0; j < (int)mat[i].size(); j++) {
                            mat[i][j]=mat_guardar[i][j];
                    }
                }
                mat[posicao.x][posicao.y] = "0";
            }
            else {
                posicao.y = posicao.y-1;
                mat[posicao.x][posicao.y] = "0";
                //print1(mat);
            }
        }
        //diagonal superior direita 
        if (possivel_direcao == 5 && posicao.x != 0 && posicao.y != mat.size()-1 && mat[posicao.x-1][posicao.y+1] != "#" && mat[posicao.x-1][posicao.y+1] != "0") {
            //cout << endl << "Vou pra diagonal superior direita" << endl;
            casas_percorridas ++;
            comparacao = mat[posicao.x-1][posicao.y+1];
            
            if (comparacao == "?") {
                cout << endl << "============= ENCONTROU O '?' =============" << endl;
                mat[posicao.x-1][posicao.y+1] = "X";
                achou = true;
                ////print(mat);
                //clock_t end = clock();
                //double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
                chrono::steady_clock::time_point end= chrono::steady_clock::now();
                chrono::duration<double> elapsed_seconds = chrono::duration_cast<chrono::duration<double>>(end - begin);
                cout << endl << endl << "=======================================================================================" << endl;
                cout << endl << "A BUSCA RANDÔMICA DEMOROU: " << elapsed_seconds.count() << " SEGUNDOS PARA ENCONTRAR A '?'" << endl;
                cout << "CASAS PERCORRIDAS: " << casas_percorridas;
                cout << endl << "=======================================================================================" << endl << endl << endl;
                print1(mat);
            }
            else if (comparacao == "*") {
                //cout << endl << "Encontrou um '*'" << endl <<"Voltando a posicao inicial" << endl;
                casas_percorridas = 0;
                mat_guardar[posicao.x-1][posicao.y+1]="1";
                posicao.x=0;
                posicao.y=0;
                for (int i = 0; i < (int)mat.size(); i++) {
                    for (int j = 0; j < (int)mat[i].size(); j++) {
                            mat[i][j]=mat_guardar[i][j];
                    }
                }
                mat[posicao.x][posicao.y] = "0";
            }
            else {
                posicao.x = posicao.x-1;
                posicao.y = posicao.y+1;
                mat[posicao.x][posicao.y] = "0";
                //print1(mat);
            }
        }
        //diagonal inferior direita
        if (possivel_direcao == 6 && posicao.x != mat.size()-1 && posicao.y != mat.size()-1 && mat[posicao.x+1][posicao.y+1] != "#" && mat[posicao.x+1][posicao.y+1] != "0") {
            //cout << endl << "Vou pra diagonal inferior direita" << endl;
            casas_percorridas ++;
            comparacao = mat[posicao.x+1][posicao.y+1];
            
            if (comparacao == "?") {
                cout << endl << "============= ENCONTROU O '?' =============" << endl;
                mat[posicao.x+1][posicao.y+1] = "X";
                achou = true;
                ////print(mat);
                //clock_t end = clock();
                //double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
                chrono::steady_clock::time_point end= chrono::steady_clock::now();
                chrono::duration<double> elapsed_seconds = chrono::duration_cast<chrono::duration<double>>(end - begin);
                cout << endl << endl << "=======================================================================================" << endl;
                cout << endl << "A BUSCA RANDÔMICA DEMOROU: " << elapsed_seconds.count() << " SEGUNDOS PARA ENCONTRAR A '?'" << endl;
                cout << "CASAS PERCORRIDAS: " << casas_percorridas;
                cout << endl << "=======================================================================================" << endl << endl << endl;
                print1(mat);
            }
            else if (comparacao == "*") {
                //cout << endl << "Encontrou um '*'" << endl <<"Voltando a posicao inicial" << endl;
                casas_percorridas = 0;
                mat_guardar[posicao.x+1][posicao.y+1]="1";
                posicao.x=0;
                posicao.y=0;
                for (int i = 0; i < (int)mat.size(); i++) {
                    for (int j = 0; j < (int)mat[i].size(); j++) {
                            mat[i][j]=mat_guardar[i][j];
                    }
                }
                mat[posicao.x][posicao.y] = "0";
            }
            else {
                posicao.x = posicao.x+1;
                posicao.y = posicao.y+1;
                mat[posicao.x][posicao.y] = "0";
                //print1(mat);
            }
        }
        //diagonal inferior esquerda
        if (possivel_direcao == 7 && posicao.x != mat.size()-1 && posicao.y != 0 && mat[posicao.x+1][posicao.y-1] != "#" && mat[posicao.x+1][posicao.y-1] != "0") {
            //cout << endl << "Vou pra diagonal inferior esquerda" << endl;
            casas_percorridas ++;
            comparacao = mat[posicao.x+1][posicao.y-1];
            
            if (comparacao == "?") {
                cout << endl << "============= ENCONTROU O '?' =============" << endl;
                mat[posicao.x+1][posicao.y-1] = "X";
                achou = true;
                ////print(mat);
                //clock_t end = clock();
                //double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
                chrono::steady_clock::time_point end= chrono::steady_clock::now();
                chrono::duration<double> elapsed_seconds = chrono::duration_cast<chrono::duration<double>>(end - begin);
                cout << endl << endl << "=======================================================================================" << endl;
                cout << endl << "A BUSCA RANDÔMICA DEMOROU: " << elapsed_seconds.count() << " SEGUNDOS PARA ENCONTRAR A '?'" << endl;
                cout << "CASAS PERCORRIDAS: " << casas_percorridas;
                cout << endl << "=======================================================================================" << endl << endl << endl;
                print1(mat);
            }
            else if (comparacao == "*") {
                //cout << endl << "Encontrou um '*'" << endl <<"Voltando a posicao inicial" << endl;
                casas_percorridas = 0;
                mat_guardar[posicao.x+1][posicao.y-1]="1";
                posicao.x=0;
                posicao.y=0;
                for (int i = 0; i < (int)mat.size(); i++) {
                    for (int j = 0; j < (int)mat[i].size(); j++) {
                            mat[i][j]=mat_guardar[i][j];
                    }
                }
                mat[posicao.x][posicao.y] = "0";
            }
            else {
                posicao.x = posicao.x+1;
                posicao.y = posicao.y-1;
                mat[posicao.x][posicao.y] = "0";
                //print1(mat);
            }
        }
        //diagonal superior esquerda
        if (possivel_direcao == 8 && posicao.x != 0 && posicao.y != 0 && mat[posicao.x-1][posicao.y-1] != "#" && mat[posicao.x-1][posicao.y-1] != "0") {
            //cout << endl << "Vou pra diagonal superior esquerda" << endl;
            casas_percorridas ++;
            comparacao = mat[posicao.x-1][posicao.y-1];
            
            if (comparacao == "?") {
                cout << endl << "============= ENCONTROU O '?' =============" << endl;
                mat[posicao.x-1][posicao.y-1] = "X";
                achou = true;
                ////print(mat);
                //clock_t end = clock();
                //double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
                chrono::steady_clock::time_point end= chrono::steady_clock::now();
                chrono::duration<double> elapsed_seconds = chrono::duration_cast<chrono::duration<double>>(end - begin);
                cout << endl << endl << "=======================================================================================" << endl;
                cout << endl << "A BUSCA RANDÔMICA DEMOROU: " << elapsed_seconds.count() << " SEGUNDOS PARA ENCONTRAR A '?'" << endl;
                cout << "CASAS PERCORRIDAS: " << casas_percorridas;
                cout << endl << "=======================================================================================" << endl << endl << endl;
                print1(mat);
            }
            else if (comparacao == "*") {
                //cout << endl << "Encontrou um '*'" << endl <<"Voltando a posicao inicial" << endl;
                casas_percorridas = 0;
                mat_guardar[posicao.x-1][posicao.y-1]="1";
                posicao.x=0;
                posicao.y=0;
                for (int i = 0; i < (int)mat.size(); i++) {
                    for (int j = 0; j < (int)mat[i].size(); j++) {
                            mat[i][j]=mat_guardar[i][j];
                    }
                }
                mat[posicao.x][posicao.y] = "0";
            }
            else {
                posicao.x = posicao.x-1;
                posicao.y = posicao.y-1;
                mat[posicao.x][posicao.y] = "0";
                //print1(mat);
            }
        }
        else if (beco_sem_saida1(mat, posicao.x, posicao.y) == true) {
            //cout << endl << "Entrou no beco sem saída" << endl << "Zerando toda a matriz para iniciar uma nova busca randômica" << endl;
            casas_percorridas = 0;
            posicao.x=0;
            posicao.y=0;
            for (int i = 0; i < (int)mat.size(); i++)
                    {
                        for (int j = 0; j < (int)mat[i].size(); j++)
                        {
                            mat[i][j]=mat_guardar[i][j];
                        }
                    }
            mat[posicao.x][posicao.y] = "0";
            ////print(mat);
        }
        //usleep(300000);
        //system("clear");
    }while(achou == false);
}

bool beco_sem_saida1(vector<vector<string>> mat, int i, int j) {
    //meio
    if ((i > 0 && i < mat.size()-1) && (j > 0 && j < mat.size()-1)) {
        if ((mat[i+1][j] == "0" || mat[i+1][j] == "#") && (mat[i][j+1] == "0" || mat[i][j+1] == "#") && (mat[i-1][j] == "0" || mat[i-1][j] == "#") && (mat[i][j+1] == "0" || mat[i][j+1] == "#") && (mat[i-1][j+1] == "0" || mat[i-1][j+1] == "#") && (mat[i+1][j+1] == "0" || mat[i+1][j+1] == "#") && (mat[i+1][j-1] == "0" || mat[i+1][j-1] == "#") && (mat[i-1][j-1] == "0" || mat[i-1][j-1] == "#")) {
            return true;
        }
    }
    //extremo superior esquerdo
    else if (i == 0 && j == 0) {
        if ((mat[i+1][j] == "0" || mat[i+1][j] == "#") && (mat[i][j+1] == "0" || mat[i][j+1] == "#") && (mat[i+1][j+1] == "0" || mat[i+1][j+1] == "#")) {
            return true;
        }
    }
    //lateral esquerda
    else if ((i > 0) && (i < mat.size()-1) && (j == 0)) {
        if ((mat[i+1][j] == "0" || mat[i+1][j] == "#") && (mat[i-1][j] == "0" || mat[i-1][j] == "#") && (mat[i][j+1] == "0" || mat[i][j+1] == "#") && (mat[i-1][j+1] == "0" || mat[i-1][j+1] == "#") && (mat[i+1][j+1] == "0" || mat[i+1][j+1] == "#")) {
            return true;
        }
    }
    //extremo inferior esquerdo
    else if ((i == mat.size()-1) && (j == 0)) {
        if ((mat[i-1][j] == "0" || mat[i-1][j] == "#") && (mat[i][j+1] == "0" || mat[i][j+1] == "#") && (mat[i-1][j+1] == "0" || mat[i-1][j+1] == "#")) {
            return true;
        }
    }
    //baixo no meio
    else if ((i == mat.size()-1) && (j > 0) && (j < mat.size()-1)) {
        if ((mat[i-1][j]=="0" || mat[i-1][j]=="#") && (mat[i][j-1] == "0" || mat[i][j-1] == "#") && (mat[i][j+1] == "0" || mat[i][j+1] == "#") || (mat[i-1][j-1] == "0" || mat[i-1][j-1] == "#") && (mat[i-1][j+1] == "0" || mat[i-1][j+1] == "#")) {
            return true;
        }
    }
    //extremo inferior direito
    else if ((i == mat.size()-1) && (j == mat.size()-1)) {
        if ((mat[i-1][j] == "0" || mat[i-1][j] == "#") && (mat[i][j-1] == "0" || mat[i][j-1] == "#") && (mat[i-1][j-1] == "0" || mat[i-1][j-1] == "#")) {
            return true;
        }
    }
    //meio direito
    else if ((i > 0) && (i < mat.size()-1) && (j == mat.size()-1)) {
        if ((mat[i-1][j] == "0" || mat[i-1][j] == "#") && (mat[i][j-1] == "0" || mat[i][j-1] == "#") && (mat[i+1][j] == "0" || mat[i+1][j] == "#") && (mat[i+1][j-1] == "0" || mat[i+1][j-1] == "#") && (mat[i-1][j-1] == "0" || mat[i-1][j-1] == "#")) {
            return true;
        }
    }
    //extremo superior direito
    else if (i == 0 && j == mat.size()-1) {
        if ((mat[i+1][j] == "0" || mat[i+1][j] == "#") && (mat[i][j-1] == "0" || mat[i][j-1] == "#") && (mat[i+1][j-1] == "0" || mat[i+1][j-1] == "#")) {
            return true; 
        }
    }
    //meio superior
    else if ((i == 0) && (j > 0 && j < mat.size()-1)) {
        if ((mat[i+1][j] == "0" || mat[i+1][j] == "#") && (mat[i][j-1] == "0" || mat[i][j-1] == "#") && (mat[i][j+1] == "0" || mat[i][j+1] == "#") && (mat[i+1][j+1] == "0" || mat[i+1][j+1] == "#") && (mat[i+1][j-1] == "0" || mat[i+1][j-1] == "#")) {
            return true;
        }
    }
    else {
        return false;
 
    }
}


