#include <iostream>
#include <allegro.h>
#include "menu.hpp"
#include "menu_p.hpp"
#include "Magasin.h"
#include "Joueur.h"


int main()
{

    //DECLARATION VARIABLES
    int choix=0;
    int choix_joueur=0;
    Joueur j;
    Deck d;
    std::vector<Carte> Collection;
    std::vector <Joueur> Joueurs;

    //INITIALISATION DE ALLEGRO
    allegro_init();
    install_keyboard();
    install_mouse();
    show_mouse(screen);


    ///BIBLIOTHEQUES GRAPHIQUES ALLEGRO
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_FULLSCREEN,800, 600,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);

    }


    BITMAP* buffer = create_bitmap(800,600);
    BITMAP* buffermenu = create_bitmap(800,600);
    BITMAP* cadre_b = create_bitmap(2300,1250);
    BITMAP* carte_shop =create_bitmap(800,600);
    BITMAP* cursor = load_bitmap("cursor.bmp", NULL);
    BITMAP* play = load_bitmap("play.bmp", NULL);
    BITMAP* menup = load_bitmap("menup.bmp",NULL);
    BITMAP* terrain = load_bitmap("terrain.bmp", NULL);
    BITMAP* wallpaper = load_bitmap("wallpaper.bmp", NULL);
    BITMAP* mythologia=load_bitmap("mythologia.bmp",NULL);
    BITMAP* slogan = load_bitmap("slogan.bmp", NULL);
    BITMAP* cases_terrain = load_bitmap("cases_terrain.bmp", NULL);
    BITMAP* cadre = load_bitmap("cadre.bmp", NULL);
    BITMAP* terrain_b = load_bitmap("terrain_b.bmp", NULL);
    BITMAP* cases_terrain_b = load_bitmap("cases_terrain_b.bmp", NULL);
    BITMAP* shop = load_bitmap("shop.bmp", NULL);
    BITMAP* carte_m = load_bitmap("carte_m.bmp", NULL);
    BITMAP* carte_m_s = load_bitmap("carte_m_s.bmp", NULL);
    BITMAP* joueur_b = load_bitmap("joueur.bmp", NULL);
    BITMAP* joueur_c = load_bitmap("photo_j.bmp", NULL);
    BITMAP* save = load_bitmap("save.bmp",NULL);


    if(!wallpaper)
        allegro_message("Erreur de chargement de l'image wallpaper");
    if(!terrain)
        allegro_message("Erreur de chargement de l'image terrain");
    if(!cursor)
        allegro_message("Erreur de chargement de l'image cursor");
    if(!mythologia)
        allegro_message("Erreur de chargement de l'image mythologia");
    if(!play)
        allegro_message("Erreur de chargement de l'image play");
    if(!slogan)
        allegro_message("Erreur de chargement de l'image slogan");
    if(!menup)
        allegro_message("Erreur de chargement de l'image menup");
    if(!cases_terrain)
        allegro_message("Erreur de chargement de l'image cases terrain");
    if(!cadre)
        allegro_message("Erreur de chargement de l'image cadre");

    Magasin m;
    Collection=m.RecupFichier();

    while(!key[KEY_ESC])
    {

        ///MENU 1
        menu(&choix, buffermenu, mythologia, cursor, play, wallpaper, slogan);
        if(choix==10)
            return 0;

        ///MENU PRINCIPAL
        menu_p(d,j,&choix_joueur,save,joueur_c, Joueurs,Collection,&choix,terrain,buffermenu,cursor,screen,menup, cases_terrain, cadre,cadre_b,buffer,terrain_b,cases_terrain_b, shop,carte_m, carte_m_s,carte_shop,joueur_b);

    }

    return 0;
}
END_OF_MAIN()
