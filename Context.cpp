#include <iostream>
#include "context.h"
#include "User.h"
#include "DateTime.h"

using UUser::User;
using UDateTime::DateTime;

static User* currentUser = NULL;

// Correcto
User* UContext::GetCurrentUser(){
	if (currentUser== NULL){
	    currentUser = UUser::CreateUser("Default User");
	}
	return currentUser;
}

static DateTime* currentDateTime = NULL; // esto no va

// Correcto dejar solo currentDateTime= UDateTime::Now();
DateTime* UContext::GetNow(){
	if (currentDateTime== NULL){
	    currentDateTime= UDateTime::Now();
	}
	return currentDateTime;    
}

void UContext::DestroyContext(){
	if(currentUser != NULL){
        UUser::DestroyUser(currentUser);
        currentUser = NULL;
    }
    if(currentDateTime != NULL){
        UDateTime::DestroyDateTime(currentDateTime);
        currentDateTime = NULL;
    }
}
