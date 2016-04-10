#define BUFFER_SIZE 512

// Pool name is defined on the Oculus developer portal
#define POOL_NAME "filter_pool"

typedef struct messageStruct
{
	int packetID;
	char textString[BUFFER_SIZE];
}chatMessage;

enum states{
	NOT_INIT = 0,
	IDLE,
	REQUEST_FIND,
	FINDING_ROOM,
	REQUEST_CREATE,
	REQUEST_JOIN,
	REQUEST_LEAVE,
	IN_EMPTY_ROOM,
	IN_FULL_ROOM
};

class machineState{
public:
	machineState() {
		currentState = NOT_INIT; 
		localUserID = 0;
		remoteUserID = 0;
		roomID = 0;
	};

	~machineState(){};

	void init(ovrMessage *message);

	void requestCreateRoom();
	void createRoomResponse(ovrMessage *message);
	void requestFindMatch();
	void findMatchResponse(ovrMessage *message);
	void requestFindFilteredMatch();

	void foundMatch(ovrMessage *message);
	void joinRoomResponse(ovrMessage *message);
	void requestLeaveRoom();
	void leaveRoomResponse(ovrMessage *message);
	void requestStartRatedMatch();
	void startRatedMatchResponse(ovrMessage *message);
	void requestReportResults();
	void reportResultsResponse(ovrMessage *message);
	void sendChat(char* chatMessage);
	void updateRoom(ovrMessage *message);

private:
	int	currentState;
	int lastPacketID = 0;
	bool ratedMatchStarted = false;

	ovrID roomID;
	ovrID localUserID;
	ovrID remoteUserID;
};
