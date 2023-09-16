#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
void calcActSector(vector<int>& usedSectors, int& newSector){
    for (int i = 0; i < usedSectors.size(); i++){
        if (newSector > 13){
            newSector -= 13;
        }
        if (newSector == usedSectors[i]){
            newSector+=1;
            calcActSector(usedSectors, newSector);
        }
    }
}
void checkWin(string *massivePath,int& sector, int& winsPlayer, int& winsViewer){
    fstream sectorFile, ansFile;
    sectorFile.open(massivePath[sector-1]);
    while(!sectorFile.eof()){
        string str;
        sectorFile >> str;
        cout << str << " ";
    }
    cout << endl;
    sectorFile.close();
    string answer;
    cout << "Dear player input your answer: " << endl;
    cin.clear();
    cin.ignore();
    getline(cin,answer, ' ');
    sectorFile.open(massivePath[sector + 12]);
    string trueAnswer;
    string str2;
    while(!sectorFile.eof()){
        sectorFile >> str2;
        trueAnswer += str2;
        if (!sectorFile.eof()){
            trueAnswer += " ";
        }
    }
    cout << "Your answer is: " << answer << endl;
    cout << "True answer is: " << trueAnswer << endl;
    if (answer == trueAnswer){
        cout << "Your anwer is true" << endl;
        winsPlayer++;
    } else {
        cout << "Your answer is wrong" << endl;
        winsViewer++;
    }
    sectorFile.close();
}
int main() {
    system("chcp 65001");
    int winsPlayers = 0;
    int winsViewers = 0;
    int actSector = 1;
    int ofset = 0;
    vector<int> usedActSector;
    string massivePaths[26];
    massivePaths[0] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\sector1)";
    massivePaths[1] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\sector2)";
    massivePaths[2] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\sector3)";
    massivePaths[3] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\sector4)";
    massivePaths[4] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\sector5)";
    massivePaths[5] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\sector6)";
    massivePaths[6] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\sector7)";
    massivePaths[7] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\sector8)";
    massivePaths[8] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\sector9)";
    massivePaths[9] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\sector10)";
    massivePaths[10] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\sector11)";
    massivePaths[11] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\sector12)";
    massivePaths[12] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\sector13)";
    massivePaths[13] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\ans1)";
    massivePaths[14] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\ans2)";
    massivePaths[15] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\ans3)";
    massivePaths[16] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\ans4)";
    massivePaths[17] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\ans5)";
    massivePaths[18] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\ans6)";
    massivePaths[19] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\ans7)";
    massivePaths[20] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\ans8)";
    massivePaths[21] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\ans9)";
    massivePaths[22] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\ans10)";
    massivePaths[23] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\ans11)";
    massivePaths[24] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\ans12)";
    massivePaths[25] = R"(C:\Users\volob\CLionProjects\SkillboxCAP\M19\M19_P5\ans13)";
    while(winsPlayers < 7 || winsViewers < 7) {
        cout << "Input ofset: " << endl;
        cin >> ofset;
        actSector += ofset;
        calcActSector(usedActSector, actSector);
        checkWin(massivePaths, actSector, winsPlayers, winsViewers);
    }
    return 0;
}