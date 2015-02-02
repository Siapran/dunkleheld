/* 
 * File:   Frame.h
 * Author: siapran
 *
 * Created on February 2, 2015, 10:23 AM
 */

#ifndef FRAME_H
#define	FRAME_H

class Frame : public sf::Drawable, public sf::Transformable {
public:
    Frame();
    Frame(const Frame& orig);
    virtual ~Frame();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    
    
private:

    int m_id;
    sf::Vertex m_vertices[4];
    const sf::Texture* m_texture;

};

#endif	/* FRAME_H */

