OutputDirectory(Directory input[],Directory i)
{
	string result;
	Directory t = i;
	while(t.parentID!=-1)
	{
		result =input[t.parentID].name+result;
		t = input[t.parentID]
	}
	result = t.name+result;
	
	return result;
}