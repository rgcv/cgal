namespace CGAL {

/*!
\ingroup PkgMesh_3MeshClasses

The class `Mesh_triangulation_3` is a metafunctor which provides the  triangulation type to be used
 for the  3D  triangulation embedding the mesh. 

\tparam MD stands for a model of `MeshDomain_3`. 

\tparam Gt stands for a model of `RegularTriangulationTraits_3` 
and defaults to `Kernel_traits<MD>::Kernel`. 

\tparam Concurrency_tag is a place-holder. It is not used yet
and defaults to `Default`.

\tparam Vertex_base stands for a model of `MeshVertexBase_3` 
and defaults to `Mesh_vertex_base_3<Gt, MD>`. 

\tparam Cell_base stands for a model of `MeshCellBase_3`
and defaults to `Mesh_cell_base_3<Gt, MD>`. 

\sa `CGAL::make_mesh_3()` 
\sa `CGAL::Mesh_complex_3_in_triangulation_3<Tr,CornerIndex,CurveSegmentIndex>` 

*/
template< typename MD, typename Gt,
          typename Concurrency_tag,
          typename Vertex_base,
          typename Cell_base >
class Mesh_triangulation_3 {
public:

/// \name Types 
/// @{

/*! 
The  triangulation type to be used
 for the  3D  triangulation embedding the mesh. 
This type is a `CGAL::Regular_triangulation_3` type 
whose vertex and cell base classes are respectively 
`Vertex_base` and `Cell_base`. 
*/ 
typedef Hidden_type type; 

/// @}

}; /* end Mesh_triangulation_3 */
} /* end namespace CGAL */
