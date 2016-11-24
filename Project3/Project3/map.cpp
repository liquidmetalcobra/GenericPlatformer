#include "map.h"

//#include "stdafx.h"
void dump_to_stdout(TiXmlNode* pParent, unsigned int indent = 0);

map::map(char * mapName)
{

	parseMap(mapName);

}


map::~map()
{
}

void map::parseMap(char * mapName)
{
	TiXmlDocument doc("tileset/example.tmx");
	bool loadOkay = doc.LoadFile();
	if (loadOkay)
	{
	
		TiXmlElement *ele = doc.RootElement();
		orientation =(char *) ele->Attribute("orientation");
		renderorder = (char *) ele->Attribute("renderorder");
		
		ele->Attribute("width", &width);
		ele->Attribute("height", &height);
		ele->Attribute("tilewidth", &tileWidth);
		ele->Attribute("tileheight", &tileHeight);
		ele->Attribute("nextobjectid", &nextObjectID);
		std::cout << orientation << "\n" << renderorder << "\n" << width << "\n" << height << "\n" << tileWidth << "\n" << tileHeight << "\n" << nextObjectID << "\n";
		char * tem = (char *)ele->GetText();
		if (tem)
			std::cout << "\n" << tem;
		
        
        TiXmlNode* pChild;
        for (pChild = ele->FirstChild(); pChild != 0; pChild = pChild->NextSibling())
        {
            //std::cout << "\n" << pChild->Value();
            if (!strcmp(pChild->Value(),"tileset"))
            {
                ele = pChild->ToElement();
                char * name, *imageName;
                int tw,th,tc,c,iw,ih,gid;
                ele->Attribute("firstgid",&gid);
                name = (char *)ele->Attribute("name");
                ele->Attribute("tilewidth",&tw);
                ele->Attribute("tileheight",&th);
                ele->Attribute("tilecount",&tc);
                ele->Attribute("columns",&c);
                ele = ele->FirstChild()->ToElement();
                imageName = (char *)ele->Attribute("source");
                ele->Attribute("width",&iw);
                ele->Attribute("height",&ih);
                tileset *ts = new tileset(name,gid,tw,th,tc,c,imageName,iw,ih);
                tilesets.push_back(*ts);
                
            }
            
            if (!strcmp(pChild->Value(),"layer"))
            {
                ele = pChild->ToElement();
                char * name;
                int h,w;
                name = (char *)ele->Attribute("name");
                ele->Attribute("width",&w);
                ele->Attribute("height",&h);
                
                std::vector<std::vector<int> > *g = new std::vector<std::vector<int> >(w, std::vector<int>(h));
                g->assign(w, std::vector<int>(h,0));
                TiXmlNode *childCounter = ele->FirstChild()->FirstChild();
                ele = childCounter->ToElement();
                printf("HIHIHI\n");
                for (int i = 0; i < w; i ++)
                {
                    std::vector<int> v;
                    for (int j = 0; j < h; j++)
                    {
                        int gid;
                        
                        ele->Attribute("gid",&gid);
                        printf("%d\t",gid);
                        g->at(i).at(j)=gid;
                        
                        childCounter = childCounter->NextSibling();
                        
                        if (childCounter)
                            ele = childCounter->ToElement();
                    }
                    printf("\n");
                    
                    //g.push_back(v);
                }
                layer *l = new layer(name,w,h,g);
                layers.push_back(*l);
            }
                
        }

	}
}


void map::draw()
{
    std::cout << "HIHIHI\n";
    //for (int i = 0; i < 3; i++)
        layers.at(0).draw(tilesets);
    
}