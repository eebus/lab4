#ifndef MNS_H
#define MNS_H
#include "NameServerInterface.h"
#include <string>
#include <utility>
#include <map>
using HostName = std::string;
using IPAddress = unsigned int;

class MNS: public NameServerInterface {
	
public:
	MNS();
	const IPAddress NON_EXISTING_ADDRESS = 0;
	/*
	 * Insert a name/address pair. Does not check if the name
	 * or address already exists.
	 */
	 void insert(const HostName&, const IPAddress&);
	
	/*
	 * Remove the pair with the specified host name. Returns true
	 * if the host name existed and the pair was removed, false
	 * otherwise.
	 */
	 bool remove(const HostName&);
	
	/*
	 * Find the IP address for the specified host name. Returns
	 * NON_EXISTING_ADDRESS if the host name wasn't in the name
	 * server.
	 */
	 IPAddress lookup(const HostName&) const;

private:
	std::map<HostName,IPAddress> addresses;
};

#endif