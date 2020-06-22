#ifndef MESSAGE_DYARY
#define MESSAGE_DIARY
    struct time
    {
        string date;
        string hours;
    }
    struct message
    {
        string content;
        time h;
        bool compare_message(std::string other_message){
            other_message == message;
        }
        bool on_file(std::string file)
        {
            //search for message on file
        }
        
    }
    int verify_file(std::string file);// read file for other functions
    bool error(std::string name); //errors in executions  
    void add_message(std::string file, message m); // add message to file
    void list(std::string file);//list messages 
#endif
