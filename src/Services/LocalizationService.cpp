//
// Created by jorge on 15/11/2022.
//

#include "LocalizationService.h"

#pragma region Constructor Functions

std::vector<std::string> getKeyValues(const std::string& nullValue,const std::string& englishValue,const std::string& spanishValue){
    std::vector<std::string> result(3);
    result[0] = nullValue;
    result[1] = englishValue;
    result[2] = spanishValue;
    return result;
}

std::string getWelcomeMessage(){
    std::string kingHeader = "\n[==================== KING: Making the world playful ====================]\n";
    std::string englishWelcome = "Welcome to the best program ever! :) Please select a language:\n";
    std::string spanishWelcome = "Bienvenido al mejor programa del mundo! :) Por favor escoge un idioma:\n";
    std::string languageOptions = "1: English\n2: Espanol";
    std::string fullWelcome = kingHeader + englishWelcome + spanishWelcome + languageOptions;
    return fullWelcome;
}


LocalizationService::LocalizationService() {
    currentLanguage = Null;
    buildDatabase();
}

std::string LocalizationService::getMessage(const std::string& key) {
    if(!database.contains(key))throw RuntimeError(key + " not present in localization database");
    return database.get(key)[currentLanguage];
}

void LocalizationService::changeLanguage(int newLanguageID) {
    currentLanguage = static_cast<Languages>(newLanguageID);
}

void LocalizationService::buildDatabase() {
    database.add("_Welcome", getKeyValues(getWelcomeMessage(), nullMsg, nullMsg));
    database.add("_InputError", getKeyValues("Input not valid :( Please try again...\nEl valor introducido no es valido :( Por favor intentalo de nuevo...",
                                             "Input not valid :( Please try again...",
                                             "El valor introducido no es valido :( Por favor intentalo de nuevo..."));
    database.add("_LanguageSelected", getKeyValues(nullMsg,
                                                   "Language selected: English",
                                                   "Idioma seleccionado: Espanol"));
    database.add("_Menu", getKeyValues(nullMsg,
                                       "Please select an option:\n"
                                       "1. Create User\n"
                                       "2. Send Message\n"
                                       "3. Receive All Messages For User\n"
                                       "4. Quit",
                                       "Por favor,selecciona una opcion:\n"
                                       "1. Crear usuario\n"
                                       "2. Enviar mensaje\n"
                                       "3. Recibir mensajes para un usuario\n"
                                       "4. Cerrar"));
    database.add("_AskUserName", getKeyValues(nullMsg,"Please enter user name:","Por favor introduce el nombre de usuario:"));
    database.add("_UserExists", getKeyValues(nullMsg,"ERROR: User already exists :(","ERROR: Ese usuario ya existe :("));
    database.add("_UserAdded", getKeyValues(nullMsg,"User added correctly :","Usuario anadido correctamente: "));




    database.add("_Quit", getKeyValues(nullMsg,"Are you sure you want to quit?(y/n)","Estas seguro de cerrar el programa?(s/n)"));
    database.add("_Bye", getKeyValues(nullMsg,"See you later alligator!","Ta' luego cara huevo!"));
    database.add("_OutboxFrom", getKeyValues(nullMsg,"From:","Remitente:"));
    database.add("_NoUser", getKeyValues(nullMsg,"User not found :( going back to the menu","Usuario no encontrado :( retornando al menu"));
    database.add("_OutboxTo", getKeyValues(nullMsg,"To:","Destinatario:"));
}

#pragma  endregion
