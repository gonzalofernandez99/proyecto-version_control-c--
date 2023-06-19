#ifndef COMMIT_H_
#define COMMIT_H_

#include <string>
#include "User.h"
#include "DateTime.h"
#include "Context.h"
#include <random>

using std::string;
using UDateTime::DateTime;
using UUser::User;

namespace UGit{
	struct Commit{
		Commit* parent;
        string message;
        DateTime* date;
        User* author;
        string hashCode;
	};

	std::string generateRandomHash() {
        std::string characters = "0123456789abcdefghijklmnopqrstuvwxyz";
        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::uniform_int_distribution<> distribution(0, characters.size() - 1);

        std::string random_string;
        for (std::size_t i = 0; i < 40; ++i) {
            random_string += characters[distribution(generator)];
        }
        return random_string;
    }
	// Precondicion: Ninguna
	// Postdondicion: Crea una instancia valida de un Commit el cual debe tener
	// - Un commit predecesor (@parent) el cual puede ser NULL
	// - Un mensaje (@message) que describe los objetivos de los cambios que se hicieron en el commit
	// - Un HashCode que por ahora sera simplemente un codigo alfanumerico de 40 caracteres randoms, los caracteres deben estar en minusculas
	// - Una fecha y hora actual del momento de creacion obtenida de Context.h
	// - El usuario que se encuentra en el contexto de la operacion obtenido de Context.h
	Commit* CreateCommit(Commit* parent, string message){
		Commit* new_commit = new Commit;
    	new_commit->parent = parent;
    	new_commit->message = message;
    	new_commit->date = UContext::GetNow();
    	new_commit->author = UContext::GetCurrentUser();
    	new_commit->hashCode = generateRandomHash();
    	return new_commit;
	}

	// Precondicion: @commit es una intancia valida
	// Postcondicion: Devuelve la fecha y hora de creacion del @commit
	DateTime* GetDate(const Commit* commit){
		return commit->date;
		
	}

	// Precondicion: @commit es una intancia valida
	// Postcondicion: Devuelve el usuario autor del @commit
	User* GetAuthor(const Commit* commit){
		return commit->author;
	}

	// Precondicion: @commit es una intancia valida
	// Postcondicion: Devuelve el mensaje asociado al @commit
	string GetMessage(const Commit* commit){
		return commit->message;
	}

	// Precondicion: @commit es una intancia valida
	// Postcondicion: Devuelve el commit predecesor de @commit
	Commit* GetParent(const Commit* commit){
		return commit->parent;
	}

	// Precondicion: @commit es una intancia valida
	// Postcondicion: Devuelve el hash code de @commit
	string GetHashCode(const Commit* commit){
		return commit->hashCode;
	}

	// Precondicion: @commit es una intancia valida
	// Postcondicion: Devuelve los primero ocho caracteres del hash code de @commit
	string GetShortHashCode(const Commit* commit){
		return commit->hashCode.substr(0, 8);
	}

	// Precondicion: @commit es una intancia valida
	// Postcondicion: Libera todos los recursos asociados de @commit
	void DestroyCommit(Commit* commit){
		delete commit;
	}
}

#endif
