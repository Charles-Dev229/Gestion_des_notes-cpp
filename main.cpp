#include<iostream>
#include<string>
#include<vector>

using namespace std;

using Matricule = int;
using Age = int;
using Note = double;

struct Etudiant{
    Matricule matricule;
    Age age;
    string nom;
    string prenom;
    vector<Note>note;
    int nbreNote;
};
/*La saisir des informations des etudiants*/
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
    e.note.resize(e.nbreNote);
    for(int j = 0; j<e.nbreNote; j++)
    {
        do
        {
            cout<<"\t\tNote["<<j<<"] = ";
            cin>>e.note[j];
        } while (e.note[j] < 0 || e.note[j] > 20);
        
    }
}

double calculerMoyenne(const Etudiant& e)
{
    double somme = 0;
    for(size_t i =0; i < e.note.size(); i++)
    {
        somme = somme + e.note[i];
    }
    return somme / e.note.size();
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

int rechercher(vector<Etudiant>& classe, int taille, Matricule matricule)
{
    for(int i =0; i<taille; i++)
    {
        if(classe[i].matricule == matricule) return i;      
    }
    return -1;
}




int main()
{
    int nbreEtudiant, nbreNot;
    cout<<"Entrer le nombre d'etudiant: ";
    cin>>nbreEtudiant;
    vector<Etudiant>classe(nbreEtudiant);
    cout<<"Entrer le nombre de note: ";
    cin>>nbreNot;
    
    for(int k = 0; k < nbreEtudiant; k++)
    {
        classe[k].nbreNote = nbreNot;
    }
    int recherche;
    for(int i = 0; i < nbreEtudiant ; i++)
    {
        cout<<"\n====== Etudant"<< i<<"=======\n";
        saisir(classe[i]);
    }
    
    cout<<"\n============AFFICHAGE===========\n";
    for(int i =0;i<nbreEtudiant; i++)
    {
        cout<<"\n====== Etudant"<< i<<"=======\n\n";
        afficher(classe[i]);
    }
    cout<<"\n=====Rechercher etudiant=====\n";
    cout<<"Entrer matricule de l'etudiant rechercher: ";
    cin>>recherche;
    int result = rechercher(classe,nbreEtudiant,recherche);
    if(result == -1)
    {
        cout<<"L'etudiant n'existe pas"<<endl;
    }
    else{
        cout<<"L'etudiant se trouve a la position "<< result<<endl;
    }
    return 0;
}