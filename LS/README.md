# LS
 Lag switch
 
 This lag switch implements different methods found to cause lag switches in games that have a p2p (peer to peer) connection. The lag switch will start and help with forcing host to get the lag switch to work. One method that was attempted that did not work was rasdial to create a new VPN via powershell. However, throttling the bitrate of a game's executable file (or whatever executable the game ran through for a network connection) worked successfully and was much more efficient. Some games had "patches" which only stopped crazy low throttling. A bypass was to just modify the throttle just enough to cause a momentary disconnect and then reconnect within 5-10 seconds.
 
 Although 3 games are listed when running the lag switch, it can easily be modified by changing the targeted executable in the source to another .exe of a game that uses p2p connection. Popular examples are Call of Duty, Dead by Daylight, PUBG, etc. It's generally easy enough to google what type of connections are used for games (dedicated servers, p2p, etc.)
