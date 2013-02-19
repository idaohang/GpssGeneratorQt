////ParserXML.cpp
////—одержит определение методов класса ParserXML, выполн€ющего преобразование текстового описани€ модели в XML формате,
////полученного при выполнении программы-генератора архитектур Ќиконька в набор объектов класса Model

//#include "ParserXML.h"
//#include <string>
//#include <iostream>
//#include <sstream>
//#include <cstdlib>
//#include "ExponentialFunction.h"
//#include "UniformFunction.h"
//#include "TriangularFunction.h"
//#include "GaussianFunction.h"

//namespace GeneratorGPSS
//{
//	//метод считывает описание модели из потока input
//	//и согласно описанию создает набор объектов класса Model
//	void ParserXML::DescribeModel(std::ifstream &input,std::vector<Model*> &models)
//	{
//		models.clear();
//		pModels=&models;
//		ParseRecursive(input);
//	}

//	void ParserXML::ParseRecursive(std::ifstream &input)
//	{
//		char c;
//		std::string str;

//		input>>c;		//чтение открывающей кавычки
//		input>>str;		//чтение имени узла

//		if(str.compare("queueingNetworks")==0)
//		{
//			ParseQueueingNetwork(input);
//		}
//		else if(str.compare("network")==0)
//		{
//			ParseNetwork(input);
//		}
//		else if(str.compare("thread")==0)
//		{
//			ParseThread(input);
//		}
//		else if(str.compare("device")==0)
//		{
//			ParseDevice(input);
//		}
//		else if(str.compare("generator")==0)
//		{
//			ParseGenerator(input);
//		}
//	}

//	void ParserXML::ParseQueueingNetwork(std::ifstream &input)
//	{
//		std::cout<<"QUEUEINGNETWORK\n";
//		int count;
//		std::string str,propName, propValue;
//		char c;

//		input>>c;
//		while(c!='>')
//		{
//			input.putback(c);
//			getPropertyName(input,propName);
//			getPropertyValue(input,propValue);
//			std::cout<<propName<<"\n";
//			std::cout<<propValue<<"\n";

//			if(propName.compare("count")==0)
//			{
//                            sscanf(propValue.c_str(),"%d",&count);
//                                //count=atoi(propValue.c_str());
//				pModels->assign(count,0);
//				for(int i=0;i<count;i++)
//				{
//					(*pModels)[i]=new Model();
//				}
//			}
//			input>>c;
//		}

//		for(int i=0;i<count;i++)
//		{
//			curModel=i;
//			ParseRecursive(input);
//		}

//		//чтение символов до конца закрывающего тега
//		input>>c;
//		while(c!='>')
//		{
//			input>>c;
//		}
//	}
	
//	void ParserXML::ParseNetwork(std::ifstream &input)
//	{
//		std::cout<<"NETWORK\n";
//		int threads;
//		std::string str,propName, propValue;
//		char c;

//		input>>c;
//		while(c!='>')
//		{
//			input.putback(c);
//			getPropertyName(input,propName);
//			getPropertyValue(input,propValue);
//			std::cout<<propName<<"\n";
//			std::cout<<propValue<<"\n";

//			if(propName.compare("threads")==0)
//			{
//                            sscanf(propValue.c_str(),"%d",&threads);
//                                //threads=atoi(propValue.c_str());
//			}
//			input>>c;
//		}

//		curDevices.clear();
//		pGen=0;
//		pTerm=0;
//		for(int i=0;i<threads;i++)
//		{
//			curThread=i+1;
//			(*pModels)[curModel]->AddThread(curThread);
//			ParseRecursive(input);
//		}

//		//чтение символов до конца закрывающего тега
//		input>>c;
//		while(c!='>')
//		{
//			input>>c;
//		}
//	}

//	void ParserXML::ParseThread(std::ifstream &input)
//	{
//		std::cout<<"THREAD\n";
//		int devices=0;
//		std::string str,propName, propValue;
//		char c;

//		input>>c;
//		while(c!='>')
//		{
//			input.putback(c);
//			getPropertyName(input,propName);
//			getPropertyValue(input,propValue);
//			std::cout<<propName<<"\n";
//			std::cout<<propValue<<"\n";

//			if(propName.compare("devices")==0)
//			{
//                            sscanf(propValue.c_str(),"%d",&devices);

//                                //devices=atoi(propValue.c_str());

//				if(curDevices.size()==0 && pGen==0 && pTerm==0)
//				{
//					char buf[9];

//					curDevices.assign(devices,0);
//					for(int i=0;i<curDevices.size();i++)
//					{
//                                            sprintf(buf,"%d",i+1);
//                                                //itoa(i+1,buf,10);
//						curDevices[i]=new Facility();
//						curDevices[i]->SetName("B_"+std::string(buf));
//					}
//					pGen=new SingleGenerator();
//					pGen->SetName("B_0");
//					pGen->GenerateStandartStatistics();

//					pTerm=new Terminator();
//                                        sprintf(buf,"%d",curDevices.size()+1);
//					pTerm->SetName("B_"+std::string(buf));
//					nextNodeNum=curDevices.size()+2;
//					pTerm->GenerateStandartStatistics();

//					(*pModels)[curModel]->AddNode(pGen);
//					for(int i=0;i<curDevices.size();i++)
//					{
//						(*pModels)[curModel]->AddNode(curDevices[i]);
//					}
//					(*pModels)[curModel]->AddNode(pTerm);
//				}
//			}
//			else if(propName.compare("P")==0)
//			{
//				for(int i=0;i<propValue.length();i++)
//				{
//					if(propValue[i]==',')
//						propValue[i]='.';
//				}

//				//считываем матрицу
//				std::stringstream str_matrix(propValue);
//				curP.assign(curDevices.size()+2,std::vector<double>(curDevices.size()+2));
//				for(int i=0;i<curP.size();i++)
//				{
//					for(int j=0;j<curP[i].size();j++)
//					{
//						str_matrix>>curP[i][j];
//					}
//				}

//				//генератор
//				for(int i=0;i<curP[0].size();i++)
//				{
//					if(abs(curP[0][i]-1.0)<0.0001)
//					{
//						pGen->AddNode(curThread,GetNodeByNum(i));
//						break;
//					}
//					else if(curP[0][i]>0.0)
//					{
//						//добавл€ем маршрутный узел
//						Router *rout=new Router();
//						char buf[9];
//                                                //itoa(nextNodeNum++,buf,10);
//                                                sprintf(buf,"%d",nextNodeNum++);
//						rout->SetName("B_"+std::string(buf));
//						pGen->AddNode(curThread,rout);
//						for(int j=i;j<curP[0].size();j++)
//						{
//							if(curP[0][j]>0.000)
//								rout->AddNode(curThread,GetNodeByNum(j),curP[0][j]);
//						}
//						(*pModels)[curModel]->AddNode(rout);
//						break;
//					}
//				}
//				pGen->GenerateStandartStatistics(curThread);
//				//устройства
//				for(int dev=0;dev<curDevices.size();dev++)
//				{
//					for(int i=0;i<curP[dev+1].size();i++)
//					{
//						if(abs(curP[dev+1][i]-1.0)<0.0001)
//						{
//							curDevices[dev]->AddNode(curThread,GetNodeByNum(i));
//							break;
//						}
//						else if(curP[dev+1][i]>0.0)
//						{
//							//добавл€ем маршрутный узел
//							Router *rout=new Router();
//							char buf[9];
//                                                        sprintf(buf,"%d",nextNodeNum++);
//                                                        //itoa(nextNodeNum++,buf,10);
//							rout->SetName("B_"+std::string(buf));
//							curDevices[dev]->AddNode(curThread,rout);
//							for(int j=i;j<curP[dev+1].size();j++)
//							{
//								if(curP[dev+1][j]>0.000)
//									rout->AddNode(curThread,GetNodeByNum(j),curP[dev+1][j]);
//							}
//							(*pModels)[curModel]->AddNode(rout);
//							break;
//						}
//					}
//					curDevices[dev]->GenerateStandartStatistics(curThread,3);
//				}
//				//приемник
//				pTerm->GenerateStandartStatistics(curThread);
//			}
//			input>>c;
//		}

//		for(int i=0;i<devices+1;i++)
//		{
//			curDevice=i-1;
//			ParseRecursive(input);
//		}

//		//чтение символов до конца закрывающего тега
//		input>>c;
//		while(c!='>')
//		{
//			input>>c;
//		}
//	}

//	void ParserXML::ParseDevice(std::ifstream &input)
//	{
//		std::cout<<"DEVICE\n";
//		std::string str,propName, propValue;
//		char c;
//		double m;

//		Facility *pFacil=curDevices[curDevice];

//		input>>c;
//		while(c!='/')
//		{
//			input.putback(c);
//			getPropertyName(input,propName);
//			getPropertyValue(input,propValue);
//			std::cout<<propName<<"\n";
//			std::cout<<propValue<<"\n";

//			if(propName.compare("m")==0)
//			{
//				//for(int i=0;i<propValue.length();i++)
//				//{
//				//	if(propValue[i]==',')
//				//	{
//				//		propValue[i]='.';
//				//	}
//				//}
//                            sscanf(propValue.c_str(),"%lf",&m);
//                                //m=atof(propValue.c_str());
//			}
//			else if(propName.compare("k")==0)
//			{
//				pFacil->SetChanelAmount(atoi(propValue.c_str()));
//			}
//			else if(propName.compare("distribution")==0)
//			{
//				if(propValue[1]=='u')
//				{
//					UniformFunction *func=new UniformFunction();
//					func->SetParams(rand()%100+1,0.5*m,1.5*m);
//					pFacil->AddFunction(curThread,func);
//				}
//				else if(propValue[1]=='t')
//				{
//					TriangularFunction *func=new TriangularFunction();
//					func->SetParams(rand()%100+1,0.5*m,1.5*m,m);
//					pFacil->AddFunction(curThread,func);
//				}
//				else if(propValue[1]=='g')
//				{
//					GaussianFunction *func=new GaussianFunction();
//					func->SetParams(rand()%100+1,m,0.2*m);
//					pFacil->AddFunction(curThread,func);
//				}
//				else
//				{
//					ExponentialFunction *func=new ExponentialFunction();
//					func->SetParams(rand()%100+1,0,m);
//					pFacil->AddFunction(curThread,func);
//				}
//			}

//			input>>c;
//		}
//		input>>c;
//	}

//	void ParserXML::ParseGenerator(std::ifstream &input)
//	{
//		std::cout<<"GENERATOR\n";
//		std::string str,propName, propValue;
//		char c;
//		double m;

//		input>>c;
//		while(c!='/')
//		{
//			input.putback(c);
//			getPropertyName(input,propName);
//			getPropertyValue(input,propValue);
//			std::cout<<propName<<"\n";
//			std::cout<<propValue<<"\n";

//			if(propName.compare("m")==0)
//			{
//				//for(int i=0;i<propValue.length();i++)
//				//{
//				//	if(propValue[i]==',')
//				//	{
//				//		propValue[i]=',';
//				//	}
//				//}
//				m=atof(propValue.c_str());
//			}
//			else if(propName.compare("distribution")==0)
//			{
//				if(propValue[1]=='u')
//				{
//					UniformFunction *func=new UniformFunction();
//					func->SetParams(rand()%100+1,0.5*m,1.5*m);
//					pGen->AddFunction(curThread,func);
//				}
//				else if(propValue[1]='t')
//				{
//					TriangularFunction *func=new TriangularFunction();
//					func->SetParams(rand()%100+1,0.5*m,1.5*m,m);
//					pGen->AddFunction(curThread,func);
//				}
//				else if(propValue[1]=='g')
//				{
//					GaussianFunction *func=new GaussianFunction();
//					func->SetParams(rand()%100+1,m,0.2*m);
//					pGen->AddFunction(curThread,func);
//				}
//				else
//				{
//					ExponentialFunction *func=new ExponentialFunction();
//					func->SetParams(rand()%100+1,0,m);
//					pGen->AddFunction(curThread,func);
//				}
//			}

//			input>>c;
//		}
//		input>>c;
//	}

//	void ParserXML::getPropertyName(std::ifstream &input, std::string &propName)
//	{
//		propName.clear();
//		char tmp;

//		input>>tmp;
//		while(tmp!='=')
//		{
//			propName.push_back(tmp);
//			input>>tmp;
//		}
//	}

//	void ParserXML::getPropertyValue(std::ifstream &input, std::string &propValue)
//	{
//		input.unsetf(std::ios::skipws);
//		propValue.clear();
//		char tmp;

//		input>>tmp>>tmp;
//		while(tmp!='\"')
//		{
//			if(tmp<0)
//			{
//				//в результате проблемы с русской кодировкой
//				//при типе распределени€ "равномерный" второй символ = -128
//				//при типе распределени€ "треугольный" второй символ = -126
//				//при типе распределени€ "гаусовский" второй символ = -77
//				if(tmp==-128)
//				{
//					tmp='u';
//				}
//				else if(tmp==-126)
//				{
//					tmp='t';
//				}
//				else if(tmp==-77)
//				{
//					tmp='g';
//				}
//				else
//				{
//					tmp='a';
//				}
//			}
//			propValue.push_back(tmp);
//			input>>tmp;
//		}
//		input.setf(std::ios::skipws);
//	}

//	Node* ParserXML::GetNodeByNum(int num)
//	{
//		if(num==0)
//		{
//			return (Node*)pGen;
//		}
//		else if(num-1<curDevices.size())
//		{
//			return curDevices[num-1];
//		}
//		else
//		{
//			return pTerm;
//		}
//	}
//}
