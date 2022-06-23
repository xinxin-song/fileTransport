#include<iostream>

using namespace std;

#defin LOG(X) cout<<X<<endl;       //take some time to learn how to code an efficient log system 

enum messageCode{
    INVALID = 0,
    TXT,
    FILE,
    STREAM,
    CODEMAX
}
typedef struct Data{
    int messagecode;
    void* data; 
};

int sendMesg(Data data);
Data recvMesg();

int main()

{
    int serverfd = 0;
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd == -1) {
        LOG("sock error!! exit");
        return -1;
    }

    struct sockaddr_in serverconf;
    memset(&serverconf, 0, sizeof(serverconf));
    serverconf.sin_family = AF_INET;
    serverconf.sin_addr.s_addr = htonl(INADDR_ANY);                 //htons , htons ,int_addr. need to understand th difference between them.
    //serverconf.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverconf.sin_port = htons(5555);

    if(0 != bind(serverfd, (struct sockaddr*)&serverconf, sizeof(serverconf))) {
        LOG("bind error");
        close(serverfd);
        return -1;
    }

    if (0 != listen(serverfd, 5)) {
        LOG("listen error");
        close(serverfd);
        return -1;
    }

    int clientfd = 0;
    int len = sizeof(struct sockaddr);
    struct sockaddr_in clientconf;
    clientfd = accept(clientfd, (struct sockaddr*)&clientconf, (socklen_t*)&len);


    return 0;
}


int sendMesg(Data data) {
    switch(data.messagecode)
    {
        case TXT:
        {

        }
            break;

        case FILE:
        {

        }
            break;

        case STREAM:
        {

        }
            break;

        defaul:
            break;
    }

}


Data recvMesg() {

}