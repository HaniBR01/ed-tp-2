#include "heap.hpp"

Min_heap::Min_heap(){
    tamanho = 8;
    qtd = 0;
    Arr = new TipoItem[tamanho];
}

Min_heap::~Min_heap(){
    delete[] Arr;
}

void Min_heap::Insere(TipoItem item){
    if(qtd==tamanho){
        TipoItem* l= Arr;
        Arr = new TipoItem[2*tamanho];
        for(int i=0;i<tamanho;i++){
            Arr[i] = l[i];
        }
        delete[] l;
        tamanho*=2;
    }
    
    Arr[qtd] = item;
    int i = qtd;
    while(i!=0 && Arr[(i-1)/2].peso > Arr[i].peso){
        TipoItem t = Arr[i];
        Arr[i] = Arr[(i-1)/2];
        Arr[(i-1)/2] = t;
        i = (i-1)/2;
    }
    
    qtd++;
}

TipoItem Min_heap::RemoveMin(){
    
    if(qtd==0){
        return TipoItem(-1,-1,-1,-1);
    }
    if(qtd == 1){
        qtd--;
        return Arr[0];
    }

    TipoItem min = Arr[0];
    Arr[0] = Arr[qtd-1];
    
    int i=0, s;
    qtd--;

    if(qtd==2){
        s = 1;
    }else if(Arr[1].peso<Arr[2].peso){
        s = 1;
    }else{
        s = 2;
    }

    while(Arr[i].peso>Arr[s].peso && s<qtd){
        TipoItem t = Arr[i];
        Arr[i] = Arr[s];
        Arr[s] = t;
        if((s*2+1)>=qtd){
            break;
        }else if((s*2+2)==qtd){
            i = s; 
            s=s*2+1;
        }else if(Arr[s*2+1].peso<Arr[s*2+2].peso){
            i=s;
            s = s*2+1;
        }else{
            i=s;
            s= s*2+2;
        }

    }
    return min;
}

void Min_heap::Imprime(){
    for(int i=0;i<qtd;i++){
        Arr[i].imprime();
        cout << " ";
    }
    cout << endl;
}

bool Min_heap::Vazio(){
    if(qtd==0)
        return true;
    return false;
}

void TipoItem::imprime(){
    cout << "(" << vertice << "," << portais << "," << distancia << ")";
}

Caminho::Caminho(){
    tamanho = 8; quantidade=0;
    Vizitados = new TipoItem[tamanho];
}

Caminho::~Caminho(){
    delete[] Vizitados;
}

void Caminho::Insere(TipoItem vertice){
    if(quantidade==tamanho){
        TipoItem* velho=Vizitados;
        tamanho*=2;
        Vizitados = new TipoItem[tamanho];
        for(int i=1;i<quantidade;i++){
            Vizitados[i] = velho[i];
        }
        delete[] velho;
    }
    Vizitados[quantidade] = vertice;
    quantidade++;
}

bool Caminho::vizitado(TipoItem vertice){
    if(quantidade==0){
        return false;
    }
    for(int i=1;i<quantidade;i++){
        if(vertice.vertice == Vizitados[i].vertice && vertice.portais == Vizitados[i].portais){
            return true;
        }
    }
    return false;
}

bool Caminho::vizitado(int vertice){
    if(quantidade==0){
        return false;
    }
    for(int i=1;i<quantidade;i++){
        if(Vizitados[i].vertice == vertice){
            return true;
        }
    }
    return false;
}