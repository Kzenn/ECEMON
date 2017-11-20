#include "Deck.h"

Deck::Deck()
{
    //ctor
}

Deck::~Deck()
{
    //dtor
}

Deck::Deck(std::string _nom, int _nbre)
    :nom_deck(_nom), nbre_cartes_max(_nbre)
{

}

void Deck::setNomDeck(std::string _nom)
{
    nom_deck=_nom;
}

void Deck::setNbreCartes(int _exemplaire)
{
    nbre_cartes_deck=_exemplaire;
}

std::string Deck::getNomDeck()
{
    return nom_deck;
}

int Deck::getNbreCartes()
{
    return nbre_cartes_deck;
}

void Deck::setVectorDeck(std::vector <Carte> Deck)
{
    CollectionJoueur=Deck;
}
std::vector<Carte> Deck::getVectorDeck()
{
    return CollectionJoueur;
}


void Deck::CreationDeck(std::string nom)
{
    std::string dossier="DECK/";
    std::string exte= ".txt";
    std::string chemin;

    chemin=dossier+nom+exte;


    std::ofstream fich(chemin, std::ios::app);
    std::cout << "Opening deck" << std::endl;
    if(fich)
    {
        fich << "ENERGIE EUROPE 1 5 CARTESBMPTERRAIN/energy1europe.bmp" << std::endl;
        fich << "ENERGIE EUROPE 2 2 CARTESBMPTERRAIN/energy2europe.bmp"<< std::endl;
        fich << "ENERGIE EUROPE 3 1 CARTESBMPTERRAIN/energy3europe.bmp"<< std::endl;
        fich << "TERRAIN EUROPE 1 CARTESBMPTERRAIN/terraineurope_t.bmp"<< std::endl;
        fich << "PIEGE OEIL.D'ODIN 1 CARTESBMPTERRAIN/trap7_t.bmp"<< std::endl;
        fich << "PIEGE YGGDRASIL 1 CARTESBMPTERRAIN/trap9_t.bmp"<< std::endl;
        fich << "MAGIE AGLOOLIK 2 CARTESBMPTERRAIN/magie5_t.bmp"<< std::endl;
        fich << "MAGIE ASKAFROA 1 CARTESBMPTERRAIN/magie7_t.bmp"<< std::endl;
        fich << "MAGIE AUDHUMLA 1 CARTESBMPTERRAIN/magie9_t.bmp"<< std::endl;
        fich << "MONSTRE GARM EUROPE 1 0 1100 1100 2 CARTESBMPTERRAIN/monstre25_t.bmp"<< std::endl;
        fich << "MONSTRE GARUDA EUROPE 1 0 1400 500 1 CARTESBMPTERRAIN/monstre26_t.bmp"<< std::endl;
        fich << "MONSTRE AMAZONE EUROPE 4 0 2000 2000 1 CARTESBMPTERRAIN/monstre23_t.bmp"<< std::endl;
        fich << "MONSTRE GNOME EUROPE 1 0 300 1400 1 CARTESBMPTERRAIN/monstre27_t.bmp"<< std::endl;
        fich << "MONSTRE GRIFFON EUROPE 4 1 2300 1500 1 CARTESBMPTERRAIN/monstre32_t.bmp"<< std::endl;
        fich << "MONSTRE AITVARAS EUROPE 1 1 250 300 1 CARTESBMPTERRAIN/monstre15_t.bmp"<< std::endl;
        fich << "MONSTRE GAMAYUN EUROPE 1 0 1300 1200 1 CARTESBMPTERRAIN/monstre24_t.bmp"<< std::endl;
    }
    else
    {
        std::cout << "Cannot open deck" << std::endl;
    }
    fich.close();

}

std::vector <Carte> Deck::RecupDeck( std::string nom)
{
    std::string dossier="DECK/";
    std::string exte= ".txt";
    std::string chemin;
    std::vector <Carte> CollectionBase;

    chemin=dossier+nom+exte;
    std::ifstream fichier(chemin, std::ios::in);
    std::cout << "Opening deck 2" << std::endl;
    if(fichier)
    {
        int num=0;
        std::string type;
        std::string nom;
        int energie;
        int atk;
        int pt_energie;
        std::string domaine;
        int def;
        bool special;
        std::string path;
        int nbre_exemplaires;
        const char* acces;
        do
        {
            fichier >> type;
            if(type=="MONSTRE")
            {
                fichier >> nom >> domaine >> energie >> special >> atk >> def >> nbre_exemplaires>> path;
                Monstre maCarte;
                maCarte.AjouterCarteMonstre(maCarte,nom,domaine,energie,special,atk,def,nbre_exemplaires,path);
                ///AJOUT DE LA CARTE DANS LA COLLECTION
                CollectionBase.push_back(maCarte);
                acces=path.c_str();
                maCarte.AffichInfo(acces);

            }
            else if(type=="MAGIE" || type=="PIEGE")
            {
                fichier >>  nom >>  nbre_exemplaires>>path;
                if(type=="MAGIE")
                {
                    Magie maCarte;
                    domaine="_";
                    maCarte.AjouterCarteMagie(maCarte,type,domaine,nbre_exemplaires,path);
                    CollectionBase.push_back(maCarte);
                    acces=path.c_str();
                    maCarte.AffichInfo(acces);


                }
                if(type=="PIEGE")
                {
                    Piege maCarte;
                    domaine="_";
                    maCarte.AjouterCartePiege(maCarte,type,domaine,nbre_exemplaires,path);
                    CollectionBase.push_back(maCarte);
                    acces=path.c_str();
                    maCarte.AffichInfo(acces);

                }

            }
            else if(type=="ENERGIE")
            {
                fichier >> domaine >> pt_energie >>  nbre_exemplaires>>path;
                Energie maCarte;
                maCarte.AjouterCarteEnergie(maCarte,type,domaine,pt_energie,nbre_exemplaires,path);
                CollectionBase.push_back(maCarte);
                acces=path.c_str();
                maCarte.AffichInfo(acces);



            }
            if(type=="TERRAIN")
            {
                fichier >>  nom >> nbre_exemplaires>>path;
                Terrain maCarte;
                maCarte.AjouterCarteTerrain(maCarte,nom,domaine,nbre_exemplaires,path);
                CollectionBase.push_back(maCarte);
                acces=path.c_str();
                maCarte.AffichInfo(acces);

            }
            std::cout << "\n";
            num++;
        }
        while(fichier.eof()==false);

        fichier.close(); // fermeture du flux
    }
    else
    {
        std::cout << "Cannot open deck 2" << std::endl;

    }
    return  CollectionBase;
}


void Deck::AfficherDeck()
{
    std::cout << "Nom du deck : " << nom_deck << std::endl;
    std::cout << "Nombre de cartes : " << nbre_cartes_deck << std::endl;
    std::cout << "Nombre de cartes max : " << nbre_cartes_max << std::endl;
}
