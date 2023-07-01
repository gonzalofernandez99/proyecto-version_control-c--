#include "CommitSymbolTable.h"

namespace UGit {

	struct Node {
		std::string hashCode;
		UGit::Commit* commit;
		Node* next;
	};

	struct CommitSymbolTable {
		Node* head;
	};

	CommitSymbolTable* CreateCommitSymbolTable() {
		CommitSymbolTable* table = new CommitSymbolTable;
		table->head = nullptr;
		return table;
	}

	Commit* GetCommit(CommitSymbolTable* table, const std::string& hashCode) {
		Node* node = table->head;
		while (node != nullptr) {
			if (node->hashCode == hashCode) {
				return node->commit;
			}
			node = node->next;
		}
		return nullptr;  // Devuelve nulo si no se encuentra el hashCode
	}

	void AddCommit(CommitSymbolTable* table, Commit* commit) {
		Node* node = new Node;
		node->hashCode = GetHashCode(commit);
		node->commit = commit;
		node->next = table->head;
		table->head = node;
	}

	void DestroyCommitSymbolTable(CommitSymbolTable* table) {
		Node* node = table->head;
		while (node != nullptr) {
			Node* next = node->next;
			DestroyCommit(node->commit);
			delete node;
			node = next;
		}
		delete table;
	}
}