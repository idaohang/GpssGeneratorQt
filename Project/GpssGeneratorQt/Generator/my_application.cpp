//#include <iostream>
//#include <cstdlib>
//#include "GeneratorHeaders.h"

//using GeneratorGPSS::ObjectGPSS;
//using GeneratorGPSS::Terminator;
//using GeneratorGPSS::Router;
//using GeneratorGPSS::ExponentialFunction;
//using GeneratorGPSS::SingleGenerator;
//using GeneratorGPSS::Facility;
//using GeneratorGPSS::Model;
//using GeneratorGPSS::Node;

//void test0()
//{
//	Model M;

//	SingleGenerator *gen=new SingleGenerator();
//	gen->SetName("B_0");
//	ExponentialFunction *gen_f=new ExponentialFunction();
//	gen_f->SetParams(1,0,10);
//	gen->AddFunction(1,gen_f);
//	gen->GenerateStandartStatistics();
//	gen->GenerateStandartStatistics(1);

//	Facility *fac=new Facility();
//	fac->SetName("B_1");
//	fac->SetChanelAmount(1);
//	ExponentialFunction *fac_f=new ExponentialFunction();
//	fac_f->SetParams(2,0,5);
//	fac->AddFunction(1,fac_f);
//	fac->GenerateStandartStatistics(1,3);

//	Terminator *term=new Terminator();
//	term->SetName("B_2");
//	term->GenerateStandartStatistics();
//	term->GenerateStandartStatistics(1);

//	Router *rout=new Router();
//	rout->SetName("B_3");
//	rout->AddNode(1,fac,0.4);
//	rout->AddNode(1,term,0.6);

//	gen->AddNode(1,fac);
//	fac->AddNode(1,rout);

//	M.AddNode((Node*)gen);
//	M.AddNode((Node*)fac);
//	M.AddNode((Node*)rout);
//	M.AddNode((Node*)term);

//	M.AddThread(1);

//	std::ofstream output("test.txt");

//	M.GenerateTextGPSS(output);

//	output.close();
//}

//void testParserXML()
//{
//	setlocale(LC_ALL,"Russian");
//	GeneratorGPSS::ParserXML p;

//	std::ifstream input;
//	input.open("bundle_test.xml",std::ios::in);
//	//std::cout<<((!input)?"not open":"open");

//	std::vector<Model*> Ms;
//	p.DescribeModel(input,Ms);

//	char buf[9];
//	for(int i=0;i<Ms.size();i++)
//	{
//		itoa(i+1,buf,8);
//		std::string filename=std::string("test_model_")+buf+".txt";
//		std::ofstream output(filename);
//		Ms[i]->GenerateTextGPSS(output);
//		output.close();
//	}

//	for(std::vector<Model*>::iterator it=Ms.begin();it!=Ms.end();it++)
//	{
//		delete (*it);
//	}

//	input.close();
//}

//void testParserXML_1()
//{
//	setlocale(LC_ALL,"Russian");
//	GeneratorGPSS::ParserXML p;

//	std::ifstream input;
//	input.open("gaus.xml"/*"triangl.xml"*//*"threads_test_1.xml"*/,std::ios::in);
//	//std::cout<<((!input)?"not open":"open");

//	std::vector<Model*> Ms;
//	p.DescribeModel(input,Ms);

//	char buf[9];
//	for(int i=0;i<Ms.size();i++)
//	{
//		itoa(i+1,buf,8);
//		std::string filename=std::string("test_threads_")+buf+".txt";
//		std::ofstream output(filename);
//		Ms[i]->GenerateTextGPSS(output);
//		output.close();
//	}

//	for(std::vector<Model*>::iterator it=Ms.begin();it!=Ms.end();it++)
//	{
//		delete (*it);
//	}

//	input.close();
//}


//void testing(std::string fileName)
//{
//	setlocale(LC_ALL,"Russian");
//	GeneratorGPSS::ParserXML p;

//	std::ifstream input;
//	input.open(fileName,std::ios::in);

//	std::vector<Model*> Ms;
//	p.DescribeModel(input,Ms);

//	char buf[9];
//	for(int i=0;i<Ms.size();i++)
//	{
//		itoa(i+1,buf,8);
//		std::string filename=fileName.substr(0,fileName.length()-4)+"_"+buf+".txt";
//		std::ofstream output(filename);
//		Ms[i]->GenerateTextGPSS(output);
//		output.close();
//	}

//	for(std::vector<Model*>::iterator it=Ms.begin();it!=Ms.end();it++)
//	{
//		delete (*it);
//	}

//	input.close();
//}

//void mainFunction(std::string &inputFile, std::string &outputFile)
//{
//	GeneratorGPSS::ParserXML p;

//	std::ifstream input;
//	input.open(inputFile,std::ios::in);
//	if(!input)
//	{
//		std::cerr<<"Can not open input file!";
//		std::cerr<<inputFile<<"!!!\n"<<outputFile;
//	}

//	std::vector<Model*> Ms;
//	p.DescribeModel(input,Ms);

//	char buf[9];
//	for(int i=0;i<Ms.size();i++)
//	{
//		itoa(i+1,buf,8);
//		std::string filename=outputFile.substr(0,outputFile.length()-4)+"_"+buf+".txt";
//		std::ofstream output(filename);
//		Ms[i]->GenerateTextGPSS(output);
//		output.close();
//	}

//	for(std::vector<Model*>::iterator it=Ms.begin();it!=Ms.end();it++)
//	{
//		delete (*it);
//	}

//	input.close();
//}

//int main1(int argc, char* argv[])
//{
//	setlocale(LC_ALL,"Russian");
//	std::string name1, name2;

//	if(argc<3)
//	{
//		std::cout<<"Enter input XML-file name: ";
//		std::cin>>name1;
//		std::cout<<"Enter output txt-file name: ";
//		std::cin>>name2;
//	}
//	else
//	{
//		int i=0;
//		while(argv[1][i]!='\0')
//		{
//			name1.push_back(argv[1][i]);
//			i++;
//		}
//		i=0;
//		while(argv[2][i]!='\0')
//		{
//			name2.push_back(argv[2][i]);
//			i++;
//		}
//	}

//	mainFunction(name1, name2);

//	return 0;
//}
