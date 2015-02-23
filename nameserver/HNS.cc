
#include "hns.h"
#include <string>
#include <utility>
#include <algorithm>
#include<iostream>
using namespace std;
 HNS::HNS(int s){
	 size=s;
	 addresses(size);
	//std::vector<std::pair<HostName,IPAddress>> addresses;
 }

/*
 * Insert a name/address pair. Does not check if the name
 * or address already exists.
 */
 void HNS::insert(const HostName& h, const IPAddress& ip){
	 pair<HostName,IPAddress> p(h,ip);
	 addresses.push_back(p);
	
 }

/*
 * Remove the pair with the specified host name. Returns true
 * if the host name existed and the pair was removed, false
 * otherwise.
 */
 bool HNS::remove(const HostName& h){
	  
	  auto r=std::find_if(addresses.begin(), addresses.end(),[h](pair<HostName,IPAddress> x) { return x.first == h; });
	  if(r==addresses.end()){
			return false;
	  }else{
		  addresses.erase(r);
		  return true;
	  }
 }

/*
 * Find the IP address for the specified host name. Returns
 * NON_EXISTING_ADDRESS if the host name wasn't in the name
 * server.
 */
 IPAddress HNS::lookup(const HostName& h) const{
	 auto r=std::find_if(addresses.begin(), addresses.end(),[h](pair<HostName,IPAddress> x) { return x.first == h; });
	  if(r==addresses.end()){
			return NON_EXISTING_ADDRESS;
	  }else{
		  return r->second;
	  }
 }
