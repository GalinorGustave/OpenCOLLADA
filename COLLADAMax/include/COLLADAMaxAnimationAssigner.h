/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADAMax.

Portions of the code are:
Copyright (c) 2005-2007 Feeling Software Inc.
Copyright (c) 2005-2007 Sony Computer Entertainment America

Based on the 3dsMax COLLADASW Tools:
Copyright (c) 2005-2006 Autodesk Media Entertainment

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAX_ANIMATIONASSIGNER_H__
#define __COLLADAMAX_ANIMATIONASSIGNER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxImporterBase.h"

#include "COLLADAFWTransformation.h"
#include "COLLADAFWAnimationList.h"

namespace COLLADAMax
{

    /** Assigns all the controllers to the corresponding animatables. */
	class AnimationAssigner : public ImporterBase 
	{
	private:

		enum Bucket
		{ 
			TRANSLATE_X = 0, 
			TRANSLATE_Y, 
			TRANSLATE_Z, 
			TRANSLATE = TRANSLATE_Z, 
			ROTATE_Z, 
			ROTATE_Y, 
			ROTATE_X, 
			ROTATE_AXIS, 
			SCALE_AXIS_ROTATE, 
			SCALE_X,
			SCALE_Y,
			SCALE_Z,
			SCALE = SCALE_Z, 
			SCALE_AXIS_ROTATE_R, 
			BUCKET_COUNT 
		};

	
	public:

        /** Constructor. */
		AnimationAssigner( DocumentImporter* documentImporter );

        /** Destructor. */
		virtual ~AnimationAssigner();

		/** Performs the assignment.
		@return True on success, false otherwise.*/
		bool assign();

		/** Assigns all transformation controllers.*/
		bool assignTransformationControllers();

		bool assignTransformationController( const COLLADAFW::Node* node, INode* iNode );

	private:

        /** Disable default copy ctor. */
		AnimationAssigner( const AnimationAssigner& pre );

        /** Disable default assignment operator. */
		const AnimationAssigner& operator= ( const AnimationAssigner& pre );
		
		bool buckedTransforms( const COLLADAFW::TransformationPointerArray& transformations, Control** controllers );
		
		template<COLLADAFW::AnimationList::AnimationClass class_XYZ, 
				 COLLADAFW::AnimationList::AnimationClass class_X,
				 COLLADAFW::AnimationList::AnimationClass class_Y,
				 COLLADAFW::AnimationList::AnimationClass class_Z>
		bool assign3DController( Bucket bucket_X, 
							  	 Bucket bucket_Y,
								 Bucket bucket_Z,
							     const COLLADAFW::AnimationList::AnimationBindings& animationBindings, 
								 Control** controllers);
	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_ANIMATIONASSIGNER_H__