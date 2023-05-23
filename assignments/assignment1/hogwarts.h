/******************************************************
** Program: hogwarts.h
** Author: Nicole Yarbrough
** Date: 4/13/2020
** Description: Lists functions that are used in driver.cpp
** and hogwarts.cpp as well as contains struct definitions
** Input: None
** Output: None
******************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

#ifndef WIZARD_H
#define WIZARD_H
struct wizard {
  string name;
  int id;
  string password;
  string position_title; 
  float beard_length;
};

#endif

#ifndef SPELLBOOK_H
#define SPELLBOOK_H
struct spellbook {
  string title;
  string author;
  int num_pages;
  int edition;
  int num_spells;
  float avg_success_rate;
  struct spell *s;
};

#endif

#ifndef SPELL_H
#define SPELL_H
struct spell {
  string name;
  float success_rate;
  string effect; 
};

#endif

bool is_int(string);
bool check_input(ifstream&, int, char**, wizard*&, spellbook*&, int&, int&);
bool open_file(ifstream&, char*, string);
void get_wizards(ifstream&, wizard*&, int&);
spellbook * create_spellbooks(int);
void get_spellbook_data(spellbook*, int, ifstream&);
spell* create_spells(int);
void get_spell_data(spell*&, int, ifstream&);
float get_avg_success_rate(spell*, int);
int get_spellbooks(ifstream&, spellbook*&, int&);
bool find_wizard(wizard*, int, int, string, bool&);
bool login(wizard*, int, bool&);
void get_id(int&);
void swap(spellbook*&, int, int);
void duplicate_spbk_db(spellbook*, spellbook*&, int);
void page_sort(spellbook*&, spellbook*, int);
int find_empty_index(spell*, int);
int effect_sort(spellbook*, spell*&, int);
void asr_sort(spellbook*, spellbook*&, int);
int catalog_sort();
void library_catalog(spellbook*, int, bool);
void start_sort(spellbook*, int, int, bool);
void spbk_results(spellbook*, int, int, bool);
void spell_results(spell*, int, bool);
bool can_print_spellbook(spellbook*, int, bool, int);
bool can_print_spell(spell*, int, bool, int);
void print_spellbook_results(spellbook*, int, int, bool);
void print_spell_results(spell*, int, bool);
void get_output_file(fstream&);
void save_sp_file(spell*, int, bool);
void save_to_file(spellbook*, int, int, bool);
void delete_spellbook_db(spellbook*&, int);
void delete_components(wizard*&, spellbook*&, int, int);
