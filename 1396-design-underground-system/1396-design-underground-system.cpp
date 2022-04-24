class UndergroundSystem {
public:
    // hashmap for checkIn "id = {stationName, time}"
    unordered_map<int, pair<string, int>> chkIn;
    
    // hashmap for checkOut "station = {id, time}"
    unordered_map<string, pair<int, int>> chkOut;
    
    // hashmap for calculating total time & counting the no. of journeys done so far 
    unordered_map<string, pair<int, int>> count;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        chkIn[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        chkOut[stationName] = {id, t};
        string prevStation = chkIn[id].first;
        int prevTime = chkIn[id].second;
        
        string journey = prevStation + " to " + stationName;
        // total time for each journey
        count[journey].first += (t-prevTime);
        // total no. of journeys
        count[journey].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string journey = startStation + " to " + endStation;
        double totalTime = count[journey].first;
        double noOfJourneys = count[journey].second;
        return totalTime/noOfJourneys;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */