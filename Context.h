#ifndef CONTEXT_H_
#define CONTEXT_H_

#include "User.h"
#include "DateTime.h"
using UUser::User;
using UDateTime::DateTime;

namespace UContext{
	static User* currentUser = nullptr;
	static DateTime* currentDateTime = nullptr;
	// Precondicion: Ninguna
	// Postcondicion: Obtiene el usuario actual.
	// Para la entrega actual debe crear un unico usuario
	// y siempre debe devolver esa misma instancia de usuario
	User* GetCurrentUser(){
		if(currentUser == nullptr){
            currentUser = UUser::CreateUser("Default User");
        }
        return currentUser;
	}

	// Precondicion: Ninguna
	// Postcondicion: Libera todos los recursos asociados al contexto 
	DateTime* GetNow(){
		if(currentDateTime == nullptr){
            currentDateTime = UDateTime::Now();
        }
        return currentDateTime;
	}

	// Precondicion: Ninguna
	// Postcondicion: Libera todos los recursos asociados al contexto
	void DestroyContext(){
		if(currentUser != nullptr){
            UUser::DestroyUser(currentUser);
            currentUser = nullptr;
        }
        if(currentDateTime != nullptr){
            UDateTime::DestroyDateTime(currentDateTime);
            currentDateTime = nullptr;
        }
	}
}

#endif
