#include<iostream>
#include<string>

using namespace std;

using Matricule = int;
using Age = int;
using Note = double;

struct Etudiant{
    Matricule matricule;
    Age age;
    string nom;
    string prenom;
    Note note[5];
};

void saisir(Etudiant& e)
{
    cout<<"\tMatricule: ";
    cin>>e.matricule;
    cout<<"\tAge: ";
    cin>>e.age;
    cout<<"\tNom: ";
    cin>>e.nom;
    cout<<"\tPrenom: ";
    cin>>e.prenom;
    cout<<"\tLes 5 notes\n";
    for(int i = 0; i<5; i++)
    {
        cout<<"\t\tNote["<<i<<"] = ";
        cin>>e.note[i];
    }
}

double calculerMoyenne(const Etudiant& e)
{
    double somme = 0;
    for(int i =0; i< 5; i++)
    {
        somme = somme + e.note[i];
    }
    return somme / 5;
}

void afficher(const Etudiant& e)
{
    cout<<"Matricule: "<<e.matricule<<endl;
    cout<<"Nom: "<<e.nom<<endl;
    cout<<"Prenom: "<<e.prenom<<endl;
    cout<<"Age: "<<e.age<<" ans"<<endl;
    double moyenne = calculerMoyenne(e);
    cout<<"Moyenne: "<<moyenne<<"/20"<<endl;
    if(moyenne >= 10)
    {
        cout<<"Mention: Admis"<<endl;
    }
    else{
        cout<<"Mention: Non admis"<<endl;
    }
}

int rechercher(const Etudiant classe[], int taille, Matricule matricule)
{
    for(int i =0; i<taille; i++)
    {
        if(classe[i].matricule == matricule) return i;      
    }
    return -1;
}




int main()
{
    const int N = 3;
    Etudiant classe[N];
    int recherche;
    for(int i =0;i<3; i++)
    {
        cout<<"\n====== Etudant"<< i<<"=======\n";
        saisir(classe[i]);
    }
    
    for(int i =0;i<3; i++)
    {
        cout<<"\n====== Etudant"<< i<<"=======\n\n";
        afficher(classe[i]);
    }
    cout<<"=====Rechercher etudiant=====\n";
    cout<<"Entrer matricule de l'etudiant rechercher: ";
    cin>>recherche;
    int result = rechercher(classe,N,recherche);
    if(result == -1)
    {
        cout<<"L'etudiant n'existe pas"<<endl;
    }
    else{
        cout<<"L'etudiant se trouve a la position "<< result<<endl;
    }
    return 0;
}