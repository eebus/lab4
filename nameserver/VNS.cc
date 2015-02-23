
#include<VNS.h>
#include <string>
#include <pair>

 VNS::~VNS(){
	delete addresses;
 }
 VNS::VNS(){
	addresses();
 }

/*
 * Insert a name/address pair. Does not check if the name
 * or address already exists.
 */
 void VNS::insert(const HostName& h, const IPAddress& ip){
	 Pair<HostName,IPAddress> p(h,ip);
	 adresses.push(p);
 }

/*
 * Remove the pair with the specified host name. Returns true
 * if the host name existed and the pair was removed, false
 * otherwise.
 */
 bool VNS::remove(const HostName&){
	  auto r=find_if(adresses.begin(), adresses.end(),[value](Pair<HostName,IPAddress> x) { return x.first == value; });
	  if(r==adresses.end()){
			return false;
	  }else{
		  adresses.erase(r);
		  return true;
	  }
 }

/*
 * Find the IP address for the specified host name. Returns
 * NON_EXISTING_ADDRESS if the host name wasn't in the name
 * server.
 */
 IPAddress VNS::lookup(const HostName&) const{
	 
 }
