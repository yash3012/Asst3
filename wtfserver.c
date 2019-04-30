#include "wtf.h"

typedef struct threadsLL
{
    int sockfd;
    pthread_t name;
    struct threadsLL* next;
} threadsLL;

//set up the LL for threadsLL
threadsLL* front = NULL;
threadsLL* traverser = NULL;


//make the socket descriptor a global variable
int sock_des = 0;

//handles the client on a particular thread. must command calls go in here
void *clientHandler(void* client_socket){
    int socket_num = *(int*) client_socket;
    
    char client_message[256];
    memset(client_message, '\0', sizeof(client_message));
    
    while(1){
        //lets reset the string storage client_message before starting
        memset(client_message, '\0', sizeof(client_message));
        
        read_return = read(socket_num, client_message, 255);//this will read from socket and store message in client_message char array
        if(read_return  == -1)
        {
            //we are going to need to send back read error, please try again
            write(socket_num, "We had trouble reading that. Please try again.", 52);
            
        }
        char* command = strtok(client_message, ":");
        
        if(strcmp(comman, "create")){
            //server-side stuff fore create goes here
        }else if(strcmp(command, "create")){
            
        }else if(strcmp(command, "create")){
            
        }else if(strcmp(command, "create")){
            
        }else if(strcmp(command, "create")){
            
        }else if(strcmp(command, "create")){
            
        }else if(strcmp(command, "create")){
            
        }else if(strcmp(command, "create")){
            
        }else if(strcmp(command, "create")){
            
        }else{
            //if not valid command
        }
        close(socket_num);
        
        return NULL;
}

//main function madafaka
int main(int argc, char *argv[]) {
    
    signal(SIGINT, ctrlC_shutdown);
    
    int portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    int n;
    if (argc != 2) {
        printf("Error:Invalid number of arguments. \n");
        return EXIT_FAILURE;
    }
    sock_des = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_des < 0)
        printf("Error: Could not create socket bitch. \n");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sock_des, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        printf("Error: Could not perform binding. \n");
    }
    listen(sock_des,5);
    
    struct sockaddr_in cli_addr;
    clilen = sizeof(cli_addr);
    
    int client_socket;
    while(1){
        client_socket = accept(sock_des, (struct sockaddr*) &cli_addr, &clilen);
        if(client_socket > 0){
            printf("We have successfully connected to the Client\n");
            
            threadsLL* newNode = (threadsLL*) malloc(sizeof(threadsLL));
            newNode->next = NULL;
            newNode->sockfd = client_socket;
            if(front == NULL){
                //printf("Front was pointing to NULL, now points to the first node\n");
                front = newNode;
            }else {
                //printf("We added a new node to the LL\n");
                newNode->next = front;
                front = newNode;
            }
            
            pthread_create(&newNode->name, NULL, clientHandler, &client_socket);
        }
    }
    /*newsock_des = accept(sock_des, (struct sockaddr *) &cli_addr, &clilen);
    if (newsock_des < 0){
        printf("Error: Could not perform accept. \n");
    }
    bzero(buffer,256);
    n = read(newsock_des,buffer,255);
    if (n < 0) error("ERROR reading from socket");
    //reads from client here
    char* command = strtok(buffer, ":");
    if (strcmp(command, "create")==0){
        //operate on create
        
    }
    
    
    printf("Here is the message: %s\n",buffer);
    
    
    
    n = write(newsock_des,"I got your message",18);
    if (n < 0) error("ERROR writing to socket");*/
    return EXIT_SUCCESS;
}
