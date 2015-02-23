
#include "mns.h"
#include <string>
#include <utility>
#include <algorithm>
#include<iostream>
using namespace std;
 MNS::MNS(){
	//std::vector<std::pair<HostName,IPAddress>> addresses;
 }

/*
 * Insert a name/address pair. Does not check if the name
 * or address already exists.
 */
 void MNS::insert(const HostName& h, const IPAddress& ip){
	 pair<HostName,IPAddress> p(h,ip);
	 addresses.insert(p);
	
 }

/*
 * Remove the pair with the specified host name. Returns true
 * if the host name existed and the pair was removed, false
 * otherwise.
 */
 bool MNS::remove(const HostName& h){
	  return addresses.erase(h)==1;
 }

/*
 * Find the IP address for the specified host name. Returns
 * NON_EXISTING_ADDRESS if the host name wasn't in the name
 * server.
 */
 IPAddress MNS::lookup(const HostName& h) const{
	 auto r=addresses.find(h);
	  if(r==addresses.end()){
			return NON_EXISTING_ADDRESS;
	  }else{
		  return r->second;
	  }
	
 }
