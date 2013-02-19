//Statistics.cpp
//Содержит описание методов абстрактного класса узла для сбора статистики Statistics

#include "Statistics.h"

namespace GeneratorGPSS
{
	//установить следующий узел
	void Statistics::SetNode(Node* node)
	{
		this->nextNode=node;
	}
}
