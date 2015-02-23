
#include "vns.h"
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
 VNS::VNS(){
	//std::vector<std::pair<HostName,IPAddress>> addresses;
 }

/*
 * Insert a name/address pair. Does not check if the name
 * or address already exists.
 */
 void VNS::insert(const HostName& h, const IPAddress& ip){
	 pair<HostName,IPAddress> p(h,ip);
	 addresses.push_back(p);
 }

/*
 * Remove the pair with the specified host name. Returns true
 * if the host name existed and the pair was removed, false
 * otherwise.
 */
 bool VNS::remove(const HostName& h){
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
 IPAddress VNS::lookup(const HostName& h) const{
	 return 0;
 }
