#include "TCP_IP.h"

using namespace TCP_IP;

#pragma region MAC

void MAC::operator=(std::string address)
{

	for (int x = 0; x < 6; x++)
	{
		MACaddress[x] = 0;
	}

	int pos = 0; //keeps track whether working on first or last 4 bits of byte
	bool last = true; //nibbles extracted in reverse; high then low
	for (int x = 0; x < 17; x++)
	{
		unsigned char hextet;
		hextet = address[x];
		//ignore colons
		if (hextet != ':')
		{
			if (islower(hextet)) //so A is always 65
			{
				hextet = toupper(hextet);
			}
			//if hextet is a letter
			if (hextet >= 65 && hextet <= 70)
			{
				hextet -= (65 - 10);
			}
			//if hextet is a number
			if (hextet >= 48 && hextet <= 57)
			{
				hextet -= 48;
			}
			//if working on the most significant half of the byte
			if (last)
			{
				hextet = hextet << 4;//for the second 4 bits
			}
			MACaddress[pos] = MACaddress[pos] | hextet; //adds to the byte
			last = !last;
			//moves to the next byte, 
			if (last)
			{
				pos++;
			}
		}
	}

}

void MAC::operator=(MAC address)
{
	for (int x = 0; x < 6; x++)
	{
		MACaddress[x] = address.MACaddress[x];
	}
}

bool MAC::operator==(MAC eq)
{
	if (eq.MACaddress == MACaddress)
	{
		return true;
	}
	return false;
}

#pragma endregion

#pragma region IPv4

void IPv4::operator=(std::string address)
{
	int counter = 0;
	for (int x = 0; x < 4; x++)
	{
		std::string section, copy;
		while (copy != "." && counter != address.length())
		{
			copy = address[counter];
			if (copy != ".")
				section += copy;
			counter++;
		}
		//address[x] = atoi(section);
		IPv4address[x] = atoi(section.c_str());
	}

	for (int x = 0; x < 4; x++)
	{
		if (IPv4address[x] > 255)
		{
			IPv4address[x] = 0;
		}
	}
}

void IPv4::operator=(IPv4 address)
{
	for (int x = 0; x < 4; x++)
	{
		IPv4address[x] = address.IPv4address[x];
	}
}

bool IPv4::operator==(IPv4 eq)
{
	if (eq.IPv4address == IPv4address)
		return true;
	return false;
}

#pragma endregion

#pragma region packet

packet::packet()
{
	BPacket = new unsigned char;
}

bool packet::encapsulate(std::string data, IPv4 source, IPv4 dest, unsigned int protocol)
{
	if (protocol > 255)
	{
		return false;
	}

	packet::source = source;
	packet::destination = dest;
	packet::data = data;

	BPacket = (unsigned char*)malloc(11 + data.length());
	int pos = 0;
	for (int x = 0; x < 4; x++)
	{
		BPacket[pos] = source.IPv4address[x];
		pos++;
	}

	for (int x = 0; x < 4; x++)
	{
		BPacket[pos] = dest.IPv4address[x];
		pos++;
	}

	BPacket[pos] = 255;
	pos++;

	BPacket[pos] = protocol;
	pos++;

	BPacket[pos] = data.length();
	pos++;

	for (int x = 0; x < data.length(); x++)
	{
		BPacket[pos] = data[x];
		pos++;
	}
	return true;
}

void packet::unencapsulate(std::string* data, IPv4* source, IPv4* dest, int* ttl, int* protocol, int* DLength)
{
	int pos = 0;

	for (int x = 0; x < 4; x++)
	{
		source->IPv4address[x] = BPacket[pos];
		pos++;
	}

	for (int x = 0; x < 4; x++)
	{
		dest->IPv4address[x] = BPacket[pos];
		pos++;
	}
	//extract the TTL
	*ttl = BPacket[pos];
	pos++;
	//extract the protocol
	*protocol = BPacket[pos];
	pos++;
	//extract the length
	int length = BPacket[pos];
	*DLength = length;
	pos++;

	for (int x = pos; x < length + pos; x++)
	{
		*data += BPacket[x];
	}
}

#pragma endregion

#pragma region frame

frame::frame()
{
	BFrame = new unsigned char;
}

bool frame::encapsulate(packet PData, MAC sourceAdd, MAC destAdd)
{
	frame::source = sourceAdd;
	frame::dest = destAdd;
	frame::data = PData;

	int length = PData.BPacket[10];
	BFrame = (unsigned char*)malloc(22 + length);
	int pos = 0;
	for (int x = 0; x < 6; x++)
	{
		BFrame[pos] = source.MACaddress[x];
		pos++;
	}

	for (int x = 0; x < 6; x++)
	{
		BFrame[pos] = dest.MACaddress[x];
		pos++;
	}
	//encapsulate source and dest IPv4 address along with TTL, protocol and length
	int Ppos = 0;
	for (int x = 0; x < 11; x++)
	{
		BFrame[pos] = data.BPacket[x];
		pos++;
		Ppos++;
	}
	//encapsulate data
	for (int x = Ppos; x < Ppos + length; x++)
	{
		BFrame[pos] = data.BPacket[x];
		pos++;
	}

	return true;
}

void frame::unencapsulate(packet* PData, MAC* source, MAC* dest)
{
	int pos = 0;
	int length = BFrame[21];
	//extract source MAC address
	for (int x = 0; x < 6; x++)
	{
		source->MACaddress[x] = BFrame[pos];
		pos++;
	}
	//extract destination MAC address
	for (int x = 0; x < 6; x++)
	{
		dest->MACaddress[x] = BFrame[pos];
		pos++;
	}

	int Ppos = 0;
	//extract source and dest IPv4 address, TTL, protocol and length 2x4 bytes, 3x1 byte
	for (int x = 0; x < 11; x++)
	{
		PData->BPacket[Ppos] = BFrame[pos];
		pos++;
		Ppos++;
	}
	//extract data
	for (int x = pos; x < length + pos; x++)
	{
		PData->BPacket[Ppos] = BFrame[x];
		Ppos++;
	}
}
#pragma endregion