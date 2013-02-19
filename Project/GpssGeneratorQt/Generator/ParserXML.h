////ParserXML.h
////�������� ���������� ������ ParserXML, ������������ �������������� �������� ���������� ������ � XML �������,
////�����������  ��������� �������� ������ � ������ ������ Model

//#ifndef PARSER_XML_H
//#define PARSER_XML_H

//#include <fstream>
//#include <vector>
//#include "AbstractParser.h"
//#include "Facility.h"
//#include "Generator.h"
//#include "Terminator.h"
//#include "Router.h"
//#include "SingleGenerator.h"

//namespace GeneratorGPSS
//{
//	class ParserXML : public AbstractParser
//	{
//		private:
//			std::vector<Model*> *pModels;

//			int curModel;
//			int curThread;
//			std::vector<std::vector<double> > curP;
//			std::vector<Facility *> curDevices;
//			SingleGenerator *pGen;
//			Terminator *pTerm;
//			std::vector<Router *> curRouters;
//			int nextNodeNum;
//			int curDevice;


//		public:
//			//����� ��������� �������� ������ �� ������ input
//			//� �������� �������� ������� ����� �������� ������ Model
//			virtual void DescribeModel(std::ifstream &input,std::vector<Model*> &models);

//		private:

//			void ParseRecursive(std::ifstream &input);
//			void getPropertyName(std::ifstream &input, std::string &propName);
//			void getPropertyValue(std::ifstream &input, std::string &propValue);

//			void ParseQueueingNetwork(std::ifstream &input);
//			void ParseNetwork(std::ifstream &input);
//			void ParseThread(std::ifstream &input);
//			void ParseDevice(std::ifstream &input);
//			void ParseGenerator(std::ifstream &input);

//			Node* GetNodeByNum(int num);
//	};
//}

//#endif
